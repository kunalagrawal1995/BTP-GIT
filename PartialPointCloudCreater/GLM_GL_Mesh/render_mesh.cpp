#include "render_mesh.hpp"

GLuint shaderProgram;
GLuint vbo,vao;

glm::mat4 global_translation_matrix;
glm::mat4 global_rotation_matrix_x;
glm::mat4 global_rotation_matrix_y;
glm::mat4 global_rotation_matrix_z;
glm::mat4 global_rotation_matrix;

glm::mat4 model_scaling_matrix;
glm::mat4 model_translation_matrix;
glm::mat4 model_rotation_matrix_x;
glm::mat4 model_rotation_matrix_y;
glm::mat4 model_rotation_matrix_z;
glm::mat4 model_rotation_matrix;

glm::mat4 ortho_matrix;
glm::mat4 perspective_matrix;
glm::mat4 final_matrix;
glm::mat4 model_matrix;
glm::mat4 view_matrix;

std::vector<glm::vec4> v_triangle_positions;
std::vector<glm::vec4> v_triangle_colors;

GLuint uModelViewMatrix;
GLuint state_shader;

//-----------------------------------------------------------------

//loads the pts point cloud file
void load(std::string model, std::vector<glm::vec4> &model_positions, std::vector<glm::vec4> &model_colors)
{
	char * name=&model[0];
	std::ifstream file_obj;
	file_obj.open(name);
	if(file_obj.is_open())
	{
		model_positions.clear();
		model_colors.clear();
		v_triangle_positions.clear();
		v_triangle_colors.clear();
		char type;
		float inp_x,inp_y,inp_z,inp_r,inp_g,inp_b;
		int inpi_x,inpi_y,inpi_z;
		glm::vec4 inp_pos,inp_color;
		while(file_obj>>type)
		{
			if(type == 'v')
			{
				file_obj>>inp_x>>inp_y>>inp_z;
				inp_pos[0] = inp_x;
				inp_pos[1] = inp_y;
				inp_pos[2] = inp_z;
				inp_pos[3] = 1.0f;
				inp_color[0] = 1;
				inp_color[1] = 0;
				inp_color[2] = 0;
				inp_color[3] = 1.0f;
				v_triangle_positions.push_back(inp_pos);
				v_triangle_colors.push_back(inp_color);
			}
			else if(type == 'f')
			{
				file_obj>>inpi_x>>inpi_y>>inpi_z;
				model_positions.push_back(v_triangle_positions[inpi_x-1]);
				model_positions.push_back(v_triangle_positions[inpi_y-1]);
				model_positions.push_back(v_triangle_positions[inpi_z-1]);
				model_colors.push_back(v_triangle_colors[inpi_x-1]);
				model_colors.push_back(v_triangle_colors[inpi_y-1]);
				model_colors.push_back(v_triangle_colors[inpi_z-1]);
			}
			
		}
		std::cout<<name<<" is now loaded."<<std::endl;
		file_obj.close(); 
	}
	else{
		std::cout<<"No file exists with name "<< name<<std::endl;
	}
} // load closed


void save_file()
{
	std::ofstream scene_saver;
	scene_saver.open("scans/pts/test_scan_000_now.xyz", std::ios::out);
	// std::cout <<"kunal"<<std::endl;
	int WINSIZE = 512;
	float depth;
	float x,y,z,r,g,b;
	for (int i = 0; i < WINSIZE; ++i)
	{
		for (int j = 0; j < WINSIZE; ++j)
		{
			glReadPixels(i,j,1,1,GL_DEPTH_COMPONENT,GL_FLOAT,&depth);
			x = (i-256)/256.0;
			y = (j-256)/256.0;
			z = 2.0*(depth-0.5);
			if(depth == 1){
				continue;
			}
			else{
				r = 0.0; g = 0.0; b = 1.0;
				glm::vec4 p;
				if (state == 0)
					p = inverse(view_matrix) * inverse(perspective_matrix) * glm::vec4(x,y,z,1.0);
				else if (state == 1)
					p = inverse(view_matrix) * inverse(ortho_matrix) * glm::vec4(x,y,z,1.0);
				// scene_saver<<p[0] <<" "<<p[1]<<" "<<p[2]<<" "<<r<<" "<<g<<" "<<b<<std::endl;
				scene_saver<<p[0]/p[3] <<" "<<p[1]/p[3]<<" "<<p[2]/p[3]<<std::endl;
			}
		}
	}
	std::cout<<"done. depth values calculated."<<std::endl;

	scene_saver.close();

}

void initBuffersGL(void)
{
	std::string model;
	std::ifstream scene_loader;
	scene_loader.open("myscene1.scn");
	if(scene_loader.is_open()){
		scene_loader>>model;
		load(model,model_positions,model_colors);
		scene_loader>>model_xscale>>model_yscale>>model_zscale;
		scene_loader>>model_xrot>>model_xrot>>model_xrot;
		scene_loader>>model_xtrans>>model_ytrans>>model_ztrans;

		scene_loader>>eye[0]>>eye[1]>>eye[2];
		scene_loader>>lookAt[0]>>lookAt[1]>>lookAt[2];
		scene_loader>>up[0]>>up[1]>>up[2];

		scene_loader>>L>>R>>T>>B>>N>>F;
		N=N; F=F;

		L=-L;B=-B;
	}
	else {
		std::cout<< "could not find file myscene.scn"<<std::endl;
	}

	// Load shaders and use the resulting shader program
	std::string vertex_shader_file("03_vshader.glsl");
	std::string fragment_shader_file("03_fshader.glsl");

	std::vector<GLuint> shaderList;
	shaderList.push_back(csX75::LoadShaderGL(GL_VERTEX_SHADER, vertex_shader_file));
	shaderList.push_back(csX75::LoadShaderGL(GL_FRAGMENT_SHADER, fragment_shader_file));

	shaderProgram = csX75::CreateProgramGL(shaderList);
	glUseProgram( shaderProgram );

	GLuint vPosition = glGetAttribLocation( shaderProgram, "vPosition" );
	GLuint vColor = glGetAttribLocation( shaderProgram, "vColor" ); 
	uModelViewMatrix = glGetUniformLocation( shaderProgram, "uModelViewMatrix");
	state_shader = glGetUniformLocation( shaderProgram, "state");


	//Ask GL for a Vertex Attribute Object (vao)
	glGenVertexArrays (1, &vao);
	//Ask GL for a Vertex Buffer Object (vbo)
	glGenBuffers (1, &vbo);

	//Set it as the current array to be used by binding it
	glBindVertexArray (vao);
	//Set it as the current buffer to be used by binding it
	glBindBuffer (GL_ARRAY_BUFFER, vbo);

	//Copy the points into the current buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBufferData (GL_ARRAY_BUFFER, model_positions.size()*sizeof(glm::vec4)+ model_colors.size()*sizeof(glm::vec4), NULL, GL_STATIC_DRAW);
	glBufferSubData( GL_ARRAY_BUFFER, 0, model_positions.size()*sizeof(glm::vec4), &model_positions[0]);
	glBufferSubData( GL_ARRAY_BUFFER, model_positions.size()*sizeof(glm::vec4),model_colors.size()*sizeof(glm::vec4), &model_colors[0]);

	glEnableVertexAttribArray( vPosition );
	glEnable(GL_DEPTH_TEST);
	// glDepthFunc(GL_ALWAYS);
	glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
	
	glEnableVertexAttribArray( vColor );
	glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(model_positions.size()*sizeof(glm::vec4)) );
}

void renderGL(void){
	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	// gluPerspective(60.0,1.0,2.5,-5);

	// glMatrixMode(GL_MODELVIEW);
	// glLoadIdentity();
	// glPushMatrix();
		// glScalef(model_xscale,model_yscale,model_zscale);
		// glRotatef(glm::degrees(model_xrot),1,0,0);
		// glRotatef(glm::degrees(model_yrot),0,1,0);
		// glRotatef(glm::degrees(model_zrot),0,0,1);
		// glTranslatef(model_xtrans,model_ytrans,model_ztrans);
		// gluLookAt(eye[0],eye[1],eye[2],lookAt[0],lookAt[1],lookAt[2],up[0],up[1],up[2]);
	//set up global transformations set by control keys
	// global_translation_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(xtrans, ytrans, ztrans));
	// global_rotation_matrix_x = glm::rotate(glm::mat4(1.0f), xrot, glm::vec3(1.0f,0.0f,0.0f));
	// global_rotation_matrix_y = glm::rotate(glm::mat4(1.0f), yrot, glm::vec3(0.0f,1.0f,0.0f));
	// global_rotation_matrix_z = glm::rotate(glm::mat4(1.0f), zrot, glm::vec3(0.0f,0.0f,1.0f));
	// global_rotation_matrix = global_rotation_matrix_z * global_rotation_matrix_y * global_rotation_matrix_x;

	//model transformations
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	model_scaling_matrix = glm::scale(glm::mat4(1.0f), glm::vec3(model_xscale,model_yscale,model_zscale));
	model_translation_matrix = glm::translate(glm::mat4(1.0f), glm::vec3(model_xtrans,model_ytrans,model_ztrans));
	model_rotation_matrix_x = glm::rotate(glm::mat4(1.0f), model_xrot, glm::vec3(1.0f,0.0f,0.0f));
	model_rotation_matrix_y = glm::rotate(glm::mat4(1.0f), model_yrot, glm::vec3(0.0f,1.0f,0.0f));
	model_rotation_matrix_z = glm::rotate(glm::mat4(1.0f), model_zrot, glm::vec3(0.0f,0.0f,1.0f));
	model_rotation_matrix = model_rotation_matrix_z * model_rotation_matrix_y * model_rotation_matrix_x;

	view_matrix = glm::lookAt(eye, lookAt, up);
	
	GLfloat matrix_view[16];
	glGetFloatv (GL_MODELVIEW_MATRIX, matrix_view);
	glm::mat4 matrix_view4 = glm::make_mat4(matrix_view);
	// glPopMatrix();
	// matrix_view4 = glm::transpose(matrix_view4);

	GLfloat matrix_pro[16];
	glGetFloatv (GL_PROJECTION_MATRIX, matrix_pro);
	glm::mat4 matrix_pro4 = glm::make_mat4(matrix_pro);
	// glPopMatrix();
	// matrix_pro4 = glm::transpose(matrix_pro4);
	// 
	perspective_matrix = glm::perspective(glm::radians(90.0), 1.0, 1.0, -5.0);
	ortho_matrix = glm::ortho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
	
	model_matrix = model_translation_matrix * model_rotation_matrix * model_scaling_matrix;
	if (state == 0)
		final_matrix = perspective_matrix * view_matrix * model_matrix;
	else if (state == 1)
		final_matrix = ortho_matrix * view_matrix * model_matrix;

	glUniformMatrix4fv(uModelViewMatrix, 1, GL_FALSE, glm::value_ptr(final_matrix));
	glUniform1i(state_shader,state);

	glBindVertexArray (vao);
	glDrawArrays(GL_TRIANGLES, 0, model_positions.size());
	// glDrawArrays(GL_POINTS, 0, model_positions.size());
}



	int main(int argc, char** argv)
	{
	//! The pointer to the GLFW window
		GLFWwindow* window;

	//! Setting up the GLFW Error callback
		glfwSetErrorCallback(csX75::error_callback);

	//! Initialize GLFW
		if (!glfwInit())
			return -1;

	//We want OpenGL 4.0
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//This is for MacOSX - can be omitted otherwise
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
	//We don't want the old OpenGL 
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

	//! Create a windowed mode window and its OpenGL context
		window = glfwCreateWindow(512, 512, "Render Mesh", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return -1;
		}

	//! Make the window's context current 
		glfwMakeContextCurrent(window);

	//Initialize GLEW
	//Turn this on to get Shader based OpenGL
		glewExperimental = GL_TRUE;
		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			//Problem: glewInit failed, something is seriously wrong.
			std::cerr<<"GLEW Init Failed : %s"<<std::endl;
		}

	//Print and see what context got enabled
		std::cout<<"Vendor: "<<glGetString (GL_VENDOR)<<std::endl;
		std::cout<<"Renderer: "<<glGetString (GL_RENDERER)<<std::endl;
		std::cout<<"Version: "<<glGetString (GL_VERSION)<<std::endl;
		std::cout<<"GLSL Version: "<<glGetString (GL_SHADING_LANGUAGE_VERSION)<<std::endl;

	//Keyboard Callback
		glfwSetKeyCallback(window, csX75::key_callback);
	//Framebuffer resize callback
		glfwSetFramebufferSizeCallback(window, csX75::framebuffer_size_callback);

	// Ensure we can capture the escape key being pressed below
		glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	//Initialize GL state
		csX75::initGL();
		initBuffersGL();

	// Loop until the user closes the window
		while (glfwWindowShouldClose(window) == 0)
		{

			// Render here
			renderGL();

			// Swap front and back buffers
			glfwSwapBuffers(window);
			
			// Poll for and process events
			glfwPollEvents();
		}

		glfwTerminate();
		return 0;
	}

//-------------------------------------------------------------------------



#include <GL/glut.h>
#include <GL/GL.h>
#include<math.h>
const float PI = 22.0f / 7.0f;
void SetupRC() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0, 5.0, -5.0, 5.0, -2.0, 2.0);
	

}
void DrawCircle(float centerX, float centerY, float radius,int steps)
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(centerX, centerY,0.0f);
	for (float angle = 0.0f; angle <= 2 * PI; angle += (2 * PI / steps))
	{
		float x = radius * cos(angle);
		float y = radius * sin(angle);
		glVertex3f(x, y,0.0f);
	}
	glEnd();


}
void DrawTriangle()
{
	// Use GL_TRIANGLE_FAN for the pyramid sides
	glBegin(GL_TRIANGLE_FAN);

	// Apex of the pyramid (top point)
	glVertex3f(0.0f, 1.0f, 0.0f);

	// Front face (pure red)
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.0f, 0.5f); // Front-left
	glVertex3f(0.5f, 0.0f, 0.5f);  // Front-right

	// Right face (pure green)
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.5f, 0.0f, -0.5f); // Back-right

	// Back face (pure blue)
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, 0.0f, -0.5f); // Back-left

	// Left face (pure yellow)
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, 0.0f, 0.5f); // Close the fan by returning to front-left

	glEnd();

	// Draw the base using GL_TRIANGLE_FAN
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.5f, 0.5f, 0.5f); // Gray for the base
	glVertex3f(0.0f, 0.0f, 0.0f); // Center of the base

	// Base vertices
	glVertex3f(-0.5f, 0.0f, 0.5f); // Front-left
	glVertex3f(0.5f, 0.0f, 0.5f);  // Front-right
	glVertex3f(0.5f, 0.0f, -0.5f); // Back-right
	glVertex3f(-0.5f, 0.0f, -0.5f); // Back-left
	glVertex3f(-0.5f, 0.0f, 0.5f); // Close the fan by returning to front-left

	glEnd();


}
void RenderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	 
	glRotatef(90.0, 0, 0, 1.0);
	glTranslatef(1.0, 0, 0);
 	
	DrawTriangle();
	//DrawCircle(0.0f, 0.0f, 20.0f, 200);

	glutSwapBuffers();
}

void ChangeSize(int w, int h) {
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h) glOrtho(-1.5, 1.5, -1.5 / aspectRatio, 1.5 / aspectRatio, -10.0, 10.0);
	else glOrtho(-1.5 * aspectRatio, 1.5 * aspectRatio, -1.5, 1.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Colored Pyramid");
	//glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
	SetupRC();
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}

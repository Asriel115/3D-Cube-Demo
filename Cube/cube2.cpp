#include <GL/glut.h> // Include OpenGL and GLUT headers

float angle = 0.0f; // Rotation angle

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear screen and depth buffer
    glLoadIdentity(); // Reset the model-view matrix

    glTranslatef(0.0f, 0.0f, -5.0f); // Move the cube back (along the z-axis)
    glRotatef(angle, 1.0f, 1.0f, 1.0f); // Rotate the cube

    // Draw the cube
    glBegin(GL_QUADS);
        // Front face
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex3f(-1.0f, -1.0f,  1.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);
        glVertex3f( 1.0f,  1.0f,  1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);

        // Back face
        glColor3f(0.0f, 1.0f, 0.0f); // Green
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f( 1.0f, -1.0f, -1.0f);
        glVertex3f( 1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);

        // Top face
        glColor3f(0.0f, 0.0f, 1.0f); // Blue
        glVertex3f(-1.0f,  1.0f,  1.0f);
        glVertex3f( 1.0f,  1.0f,  1.0f);
        glVertex3f( 1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);

        // Bottom face
        glColor3f(1.0f, 1.0f, 0.0f); // Yellow
        glVertex3f(-1.0f, -1.0f,  1.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);
        glVertex3f( 1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);

        // Left face
        glColor3f(1.0f, 0.0f, 1.0f); // Magenta
        glVertex3f(-1.0f, -1.0f,  1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);

        // Right face
        glColor3f(0.0f, 1.0f, 1.0f); // Cyan
        glVertex3f( 1.0f, -1.0f,  1.0f);
        glVertex3f( 1.0f,  1.0f,  1.0f);
        glVertex3f( 1.0f,  1.0f, -1.0f);
        glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();

    glutSwapBuffers(); // Swap the front and back buffers
}

void update(int value) {
    angle += 2.0f; // Increment rotation angle
    if (angle > 360) {
        angle -= 360;
    }
    glutPostRedisplay(); // Redraw the scene
    glutTimerFunc(16, update, 0); // Call update every 16ms (~60 FPS)
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height); // Set the viewport
    glMatrixMode(GL_PROJECTION); // Switch to the projection matrix
    glLoadIdentity(); // Reset the projection matrix
    gluPerspective(45.0, (double)width / (double)height, 1.0, 200.0); // Set perspective projection
    glMatrixMode(GL_MODELVIEW); // Switch back to the model-view matrix
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Enable double buffering, RGB, and depth
    glutInitWindowSize(800, 600); // Set window size
    glutCreateWindow("Spinning 3D Cube"); // Create window with title

    glEnable(GL_DEPTH_TEST); // Enable depth testing

    glutDisplayFunc(display); // Register display callback
    glutReshapeFunc(reshape); // Register reshape callback
    glutTimerFunc(25, update, 0); // Register timer callback

    glutMainLoop(); // Enter the GLUT event loop
    return 0;
}

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
int win = 50;
float aspecto;
float largura, altura;
int ang;

int posx = 50;

void inicializa(){
    glClearColor(5,5,5,0);

}

void desenhaCasa(void){
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-15.0f, -15.0f);
        glVertex2f(-15.0f, 5.0f);
        glVertex2f(15.0f, 5.0f);
        glVertex2f(15.0f, -15.0f);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-4.0f, -14.5f);
        glVertex2f(-4.0f, 0.0f);
        glVertex2f(4.0f, 0.05f);
        glVertex2f(4.0f, -14.5f);
        glVertex2f(7.0f, -5.0f);
        glVertex2f(7.0f, -1.0f);
        glVertex2f(13.0f, -1.0f);
        glVertex2f(13.0f, -5.0f);
    glEnd();
    glColor3f(0.0f, 0.0f, 1.0f);//RGB
     glBegin(GL_LINES);
        glVertex2f(7.0f, -3.0f);
        glVertex2f(13.0f, -3.0f);
        glVertex2f(10.0f, -1.0f);
        glVertex2f(10.0f, -5.0f);
    glEnd();
    glColor3f(1.0f, 0.0f, 0.0f);//RGB

    glBegin(GL_TRIANGLES);
        glVertex2f(-15.0f, 5.0f);
        glVertex2f(0.0f, 17.0f);
        glVertex2f(15.0f, 5.0f);
    glEnd();
}

void fazMoldura(){
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-win*aspecto, -win);
        glVertex2f(-win*aspecto, win);
        glVertex2f(win*aspecto, win);
        glVertex2f(win*aspecto, -win);
    glEnd();
    glLineWidth(1);
}


void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, largura, altura);
    glRotated(ang, 0,0, 1)
    desenhaCasa();
    fazMoldura();
    glViewport(largura, 0, largura, altura);
    desenhaCasa();
    fazMoldura();
    glFlush();
}

void funcaoMenu(int opcao){
    switch(opcao){
        case 0: glClearColor(1,0,0,1);break;
        case 1: glClearColor(0,1,0,1);break;
        case 2: glClearColor(0,0,1,1);break;
        case 3: glClearColor(0,0,0,0);break;
        case 4: glClearColor(1,1,1,1);break;
    }
    glutPostRedisplay();//Disparando o desenha.
}

void alteraTamnhoJanela(GLsizei w, GLsizei h){
    //Evita divisão por zero
    if(h==0) h = 1;

    largura = w/2;
    altura = h;
    aspecto = (float) largura/altura;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-win*aspecto, win*aspecto, -win, win);
}

void teclado(unsigned char letra , int x, int y ){
    switch(letra){
        case 'a': printf("você apertou a letra a");break;
        case 'b': printf("você apertou a letra A");break;

    }




}
void cliqueMouse(int botao, int estado, int x, int y){

        if(botao == GLUT_RIGHT_BUTTON)
            printf("Mouse voce apertou o botao do direita [%d , %d]\n",x ,y);
        if(botao == GLUT_LEFT_BUTTON)
            printf("Mouse voce apertou o botao do esquerda [%d , %d]\n",x ,y);

}


void criaMenu(){
    int menu = glutCreateMenu(funcaoMenu);
    glutAddMenuEntry("Vermelho", 0);
    glutAddMenuEntry("verde", 1);
    glutAddMenuEntry("Azul", 2);
    glutAddMenuEntry("Preto", 3);
    glutAddMenuEntry("Branco", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);


}

int main(void){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutCreateWindow("hello world");
    inicializa();
    glutReshapeFunc(alteraTamnhoJanela);

     glutKeyboardFunc(teclado);
     glutMouseFunc(cliqueMouse);


     glClear(GL_COLOR_BUFFER_BIT);
     glFlush();

    glutDisplayFunc(desenha);//Desenhar tela

    criaMenu();

    glutMainLoop();//Roda tudo.




}

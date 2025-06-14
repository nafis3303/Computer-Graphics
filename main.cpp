#include <iostream>
#include <stdlib.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<cstring>

using namespace std;

void info()
{
    using namespace std;

    cout<<" Press d for  Day"<<endl;
    cout<<" Press n for  Night"<<endl;
    cout<<" Press s for  star shooting"<<endl;
    cout<<" Press esc for  close"<<endl;
    cout<<" Press left mouse key for  stop cloud "<<endl;
    cout<<" Press right mouse key for  stop car"<<endl;
    cout<<" Press c for  speed up of car"<<endl;
    cout<<" Press C for  speed down of car"<<endl;
    cout<<" Press b for  speed up of bus"<<endl;
    cout<<" Press B for  speed down of bus"<<endl;
    cout<<" Press m for  speed up of micro"<<endl;
    cout<<" Press M for  speed down of micro"<<endl;


}
float pi = 3.1416;
float sunPosition1 = 310;
float sunSpeed = 10;
float moonPosition = 310;
float moonSpeed = 10;
float wavePosition3= 250.0;
float waveSpeed3 = -10;
float wavesPosition3= 250.0;
float wavesSpeed3 = -10;
float wave1Position3= 250.0;
float wave1Speed3 = -10;
float wave1sPosition3= 250.0;
float wave1sSpeed3 = -10;
float carPosition3= 0.0;
float carSpeed3 = 20;
float carsPosition3= 0.0;
float carsSpeed3 = 20;
float busPosition3= 0.0;
float busSpeed3 = 30;
float bussPosition3= 0.0;
float bussSpeed3 = 30;
float microPosition3= 0.0;
float microSpeed3 = -30;
float microsPosition3= 0.0;
float microsSpeed3 = -30;
float boat1Position = 0.0;
float boat1Speed = 10;
float boat2Position2 = 0.0f;
float boat2Speed2 = -5;
float shipPosition3 = 0.0f;
float shipPositions3 = 0.0f;
float shipSpeed3 = -10;
float cloudPosition = 0;
float cloudSpeed = -15;
float cloudsPosition = 0;
float cloudsSpeed = -20;
float starsPosition = 0;
float starsSpeed = 0;
bool islighton = true;
bool isDay = true;
bool isNights= true;




void drawCircle(float cx, float cy, float radius)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416;
        float A = (i * pi) / 180; // Angle in radians
        float r = radius; // Use the passed radius
        float px = cx + r * cos(A);
        float py = cy + r * sin(A);
        glVertex2f(px, py);
    }
    glEnd();
}



void sun7()
{
    glPushMatrix();
    glTranslatef(900,sunPosition1, 0.0);
    glColor3f(1.0f, 1.0f, 0.680f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 180;
        float r = 30;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}
void updatesun(int value)
{
    sunPosition1 += sunSpeed;
    if (sunPosition1 >650.0f)
    {
        sunSpeed= 00.0f; // Reset sun position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(150, updatesun, 0);
}

void moon7()
{
    glPushMatrix();
    glTranslatef(900,moonPosition, 0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 180;
        float r = 30;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}
void updatemoon(int value)
{
    moonPosition += moonSpeed;
    if (moonPosition >650.0f)
    {
        moonSpeed= 00.0f; // Reset moon position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(150, updatemoon, 0);
}


void watersky7()
{

    glBegin(GL_QUADS); //water colour

    glColor3f(0.6f, 0.8f, 1.0f);
    glVertex2f(0,0);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex2f(0,250);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex2f(1200,250);
    glColor3f(0.6f, 0.8f, 1.0f);
    glVertex2f(1200,0);
    glEnd();

    glBegin(GL_QUADS); //sky colour

    glColor3f(255,255,255);
    glVertex2f(0,250);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(0,720);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(1200,720);
    glColor3f(0.6f, 1.0f, 1.0f);
    glVertex2f(1200,250);
    glEnd();


}

void waterskys7()
{

    glBegin(GL_QUADS); //water colour

    glColor3f(0.0f, 0.2f, 0.4f);
    glVertex2f(0,0);
    glColor3f(0.0f, 0.2f, 0.4f);
    glVertex2f(0,250);
    glColor3f(0.0f, 0.2f, 0.4f);
    glVertex2f(1200,250);
    glColor3f(0.0f, 0.2f, 0.4f);
    glVertex2f(1200,0);
    glEnd();

    glBegin(GL_QUADS); //sky colour

    glColor3f(255,255,255);
    glVertex2f(0,250);
    glColor3f(0.0f, 0.2f, 0.8f);
    glVertex2f(0,720);
    glColor3f(0.0f, 0.2f, 0.8f);
    glVertex2f(1200,720);
    glColor3f(0.0f, 0.2f, 0.8f);
    glVertex2f(1200,250);
    glEnd();


}


void wave7()
{
    glPushMatrix();
    glTranslatef(230.f, wavePosition3, 0.0f);  // Position of the first wheel
    glColor3f(0.6f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 150;
        float x = r * cos(A);
        float y = 5* sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(700.0f, wavePosition3, 0.0f);  // Position of the first wheel
    glColor3f(0.6f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 100;
        float x = r * cos(A);
        float y = 4* sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(900.0f, wavePosition3, 0.0f);  // Position of the first wheel
    glColor3f(0.6f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 50;
        float x = r * cos(A);
        float y = 2* sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}

void updatewave(int value)
{
    wavePosition3 += waveSpeed3;
    if (wavePosition3<-80.0)
    {
        wavePosition3 = 250.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(100, updatewave, 0); // Match the  boat's speed
}

void waves7()
{
    glPushMatrix();
    glTranslatef(230.f, wavePosition3, 0.0f);  // Position of the first wheel
    glColor3f(0.0f, 0.44f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 150;
        float x = r * cos(A);
        float y = 5* sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(700.0f, wavePosition3, 0.0f);  // Position of the first wheel
    glColor3f(0.0f, 0.44f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 100;
        float x = r * cos(A);
        float y = 4* sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(900.0f, wavePosition3, 0.0f);  // Position of the first wheel
    glColor3f(0.0f, 0.44f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 50;
        float x = r * cos(A);
        float y = 2* sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}

void updatewaves(int value)
{
    wavesPosition3 += wavesSpeed3;
    if (wavesPosition3<-80.0)
    {
        wavesPosition3 = 250.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(100, updatewaves, 0); // Match the  boat's speed
}

void wave17()
{
    glPushMatrix();
    glTranslatef(500.f, wave1Position3, 0.0f);  // Position of the first wheel
    glColor3f(0.6f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 100;
        float x = r * cos(A);
        float y = 5* sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(900.0f, wave1Position3, 0.0f);  // Position of the first wheel
    glColor3f(0.6f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 70;
        float x = r * cos(A);
        float y = 2* sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50.0f, wave1Position3, 0.0f);  // Position of the first wheel
    glColor3f(0.6f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 20;
        float x = r * cos(A);
        float y = 2* sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}

void updatewave1(int value)
{
    wave1Position3 += wave1Speed3;
    if (wave1Position3<-160.0)
    {
        wave1Position3 = 250.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(100, updatewave1, 0); // Match the  boat's speed
}

void wave1s7()
{
    glPushMatrix();
    glTranslatef(500.f, wave1sPosition3, 0.0f);  // Position of the first wheel
    glColor3f(0.0f, 0.44f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 100;
        float x = r * cos(A);
        float y = 5* sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(900.0f, wave1sPosition3, 0.0f);  // Position of the first wheel
    glColor3f(0.0f, 0.44f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 70;
        float x = r * cos(A);
        float y = 2* sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50.0f, wave1sPosition3, 0.0f);  // Position of the first wheel
    glColor3f(0.0f, 0.44f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 20;
        float x = r * cos(A);
        float y = 2* sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}

void updatewave1s(int value)
{
    wave1sPosition3 += wave1sSpeed3;
    if (wave1sPosition3<-160.0)
    {
        wave1sPosition3 = 250.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(100, updatewave1s, 0); // Match the  boat's speed
}

void lightoff7()
{


    for (int i = 0; i <=1200; i+=100)
    {
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        drawCircle( i+15.0f, 505.0f, 7.0f);
        glEnd();

    }

}
void lighton7()
{



    for (int i = 0; i <=1200; i+=100)
    {
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        drawCircle( i+15.0f, 505.0f, 7.0f);
        glEnd();

    }

}



void hillbridge7()
{
    glBegin(GL_TRIANGLES);//hil 1

    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(0,250);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(85,350);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(250,250);
    glEnd();

    glBegin(GL_TRIANGLES);//hil 1

    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(85,350);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(180,250);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(250,250);
    glEnd();

    glBegin(GL_TRIANGLES);//hil 2

    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(150,250);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(200,320);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(290,250);
    glEnd();

    glBegin(GL_TRIANGLES);//hil 2

    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(200,320);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(290,250);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(250,250);
    glEnd();

    glBegin(GL_TRIANGLES);//hil 3

    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(1200,250);
    glVertex2f(1125,350);
    glVertex2f(970,250);
    glEnd();

    glBegin(GL_TRIANGLES);//hil 3

    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(1125,350);
    glVertex2f(970,250);
    glVertex2f(1030,250);
    glEnd();

    glBegin(GL_TRIANGLES);//hil 4

    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(1050,250);
    glVertex2f(1000,320);
    glVertex2f(910,250);
    glEnd();

    glBegin(GL_TRIANGLES);//hil 4

    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(1000,320);
    glVertex2f(910,250);
    glVertex2f(940,250);
    glEnd();




    glBegin(GL_QUADS); //bridge

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0,370);
    glVertex2f(0,420);
    glVertex2f(1200,420);
    glVertex2f(1200,370);
    glEnd();

    glBegin(GL_QUADS); //bridge

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(0,410);
    glVertex2f(0,420);
    glVertex2f(1200,420);
    glVertex2f(1200,410);
    glEnd();


    glBegin(GL_QUADS);// pillar 1

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(400,250);
    glVertex2f(400,370);
    glVertex2f(440,370);
    glVertex2f(440,250);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(390,370);
    glVertex2f(390,360);
    glVertex2f(450,360);
    glVertex2f(450,370);
    glEnd();



    glBegin(GL_QUADS);//pillar 2

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(300,250);
    glVertex2f(300,370);
    glVertex2f(340,370);
    glVertex2f(340,250);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(290,370);
    glVertex2f(290,360);
    glVertex2f(350,360);
    glVertex2f(350,370);
    glEnd();

    glBegin(GL_QUADS);//pillar 3

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(820,250);
    glVertex2f(820,370);
    glVertex2f(860,370);
    glVertex2f(860,250);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(810,370);
    glVertex2f(810,360);
    glVertex2f(870,360);
    glVertex2f(870,370);
    glEnd();

    glBegin(GL_QUADS);//pilar 4

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(720,250);
    glVertex2f(720,370);
    glVertex2f(760,370);
    glVertex2f(760,250);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(710,370);
    glVertex2f(710,360);
    glVertex2f(770,360);
    glVertex2f(770,370);
    glEnd();

    glLineWidth(4);
    for (int i = 0; i <=1200; i+=100)
    {
        glBegin(GL_LINES);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,420);
        glVertex2f(i,500);

        glEnd();
    }

    glLineWidth(4);
    for (int i = 0; i <=1200; i+=100)
    {
        glBegin(GL_LINES);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,500);
        glVertex2f(i+15,505);

        glEnd();
    }
}

void hillbridges7()
{
    glBegin(GL_TRIANGLES);//hil 1

    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(0,250);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(85,350);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(250,250);
    glEnd();

    glBegin(GL_TRIANGLES);//hil 1

    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(85,350);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(180,250);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(250,250);
    glEnd();

    glBegin(GL_TRIANGLES);//hil 2

    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(150,250);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(200,320);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(290,250);
    glEnd();

    glBegin(GL_TRIANGLES);//hil 2

    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(200,320);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(290,250);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(250,250);
    glEnd();

    glBegin(GL_TRIANGLES);//hil 3

    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(1200,250);
    glVertex2f(1125,350);
    glVertex2f(970,250);
    glEnd();

    glBegin(GL_TRIANGLES);//hil 3

    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(1125,350);
    glVertex2f(970,250);
    glVertex2f(1030,250);
    glEnd();

    glBegin(GL_TRIANGLES);//hil 4

    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(1050,250);
    glVertex2f(1000,320);
    glVertex2f(910,250);
    glEnd();

    glBegin(GL_TRIANGLES);//hil 4

    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex2f(1000,320);
    glVertex2f(910,250);
    glVertex2f(940,250);
    glEnd();




    glBegin(GL_QUADS); //bridge

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(0,370);
    glVertex2f(0,420);
    glVertex2f(1200,420);
    glVertex2f(1200,370);
    glEnd();

    glBegin(GL_QUADS); //bridge

    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(0,410);
    glVertex2f(0,420);
    glVertex2f(1200,420);
    glVertex2f(1200,410);
    glEnd();

    glBegin(GL_QUADS);// pillar 1

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(400,250);
    glVertex2f(400,370);
    glVertex2f(440,370);
    glVertex2f(440,250);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(390,370);
    glVertex2f(390,360);
    glVertex2f(450,360);
    glVertex2f(450,370);
    glEnd();



    glBegin(GL_QUADS);//pillar 2

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(300,250);
    glVertex2f(300,370);
    glVertex2f(340,370);
    glVertex2f(340,250);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(290,370);
    glVertex2f(290,360);
    glVertex2f(350,360);
    glVertex2f(350,370);
    glEnd();

    glBegin(GL_QUADS);//pillar 3

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(820,250);
    glVertex2f(820,370);
    glVertex2f(860,370);
    glVertex2f(860,250);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(810,370);
    glVertex2f(810,360);
    glVertex2f(870,360);
    glVertex2f(870,370);
    glEnd();

    glBegin(GL_QUADS);//pilar 4

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(720,250);
    glVertex2f(720,370);
    glVertex2f(760,370);
    glVertex2f(760,250);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(710,370);
    glVertex2f(710,360);
    glVertex2f(770,360);
    glVertex2f(770,370);
    glEnd();

    glLineWidth(4);
    for (int i = 0; i <=1200; i+=100)
    {
        glBegin(GL_LINES);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,420);
        glVertex2f(i,500);

        glEnd();
    }

    glLineWidth(4);
    for (int i = 0; i <=1200; i+=100)
    {
        glBegin(GL_LINES);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,500);
        glVertex2f(i+15,505);

        glEnd();
    }
}


// car 1
void car7()
{
    glPushMatrix();
    glTranslatef(carPosition3, 0.0f, 0.0f);

    // Draw car body
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(500, 425);
    glVertex2f(580, 425);
    glVertex2f(580, 445);
    glVertex2f(500, 445);
    glEnd();

    // Draw car roof
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(520, 445);
    glVertex2f(560, 445);
    glVertex2f(550, 455);
    glVertex2f(530, 455);
    glEnd();

    //window
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(522, 447);
    glVertex2f(558, 447);
    glVertex2f(548, 453);
    glVertex2f(532, 453);
    glEnd();



    // Draw first wheel
    glPushMatrix();
    glTranslatef(520.0f, 425.0f, 0.0f); // Position of the first wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 5;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Draw second wheel
    glPushMatrix();
    glTranslatef(560.0f, 425.0f, 0.0f); // Position of the second wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 5;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();
}


void cars7()
{
    glPushMatrix();
    glTranslatef(carPosition3, 0.0f, 0.0f);

    // Draw car body
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(500, 425);
    glVertex2f(580, 425);
    glVertex2f(580, 445);
    glVertex2f(500, 445);
    glEnd();

    // Draw car roof
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(520, 445);
    glVertex2f(560, 445);
    glVertex2f(550, 455);
    glVertex2f(530, 455);
    glEnd();

    //window
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(522, 447);
    glVertex2f(558, 447);
    glVertex2f(548, 453);
    glVertex2f(532, 453);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(580, 435);
    glVertex2f(580, 425);
    glVertex2f(590, 420);
    glVertex2f(605, 420);
    glEnd();




    // Draw first wheel
    glPushMatrix();
    glTranslatef(520.0f, 425.0f, 0.0f); // Position of the first wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 5;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Draw second wheel
    glPushMatrix();
    glTranslatef(560.0f, 425.0f, 0.0f); // Position of the second wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 5;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();
}



// bus 1
void bus7 ()
{
    glPushMatrix();
    glTranslatef(busPosition3, 0.0f, 0.0f);

    // Draw car body
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.3f, 1.0f);
    glVertex2f(200, 425);
    glVertex2f(350, 425);
    glVertex2f(350, 475);
    glVertex2f(200, 475);
    glEnd();


    for (int i = 205; i <= 340; i+=20)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,450);
        glVertex2f(i+18,450);
        glVertex2f(i+18,470);
        glVertex2f(i,470);
        glEnd();
    }



    // Draw first wheel
    glPushMatrix();
    glTranslatef(220.0f, 427.0f, 0.0f); // Position of the first wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Draw second wheel
    glPushMatrix();
    glTranslatef(330.0f, 427.0f, 0.0f); // Position of the second wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

}

void updatebus(int value)
{
    busPosition3 +=busSpeed3;
    if (busPosition3 > 1300.0f)
    {
        busPosition3 = -800.0f; // Reset boat position when it exits the screen

    }
    glutPostRedisplay();
    glutTimerFunc(100, updatebus, 0); // Match the  boat's speed
}
void buss7 ()
{
    glPushMatrix();
    glTranslatef(busPosition3, 0.0f, 0.0f);

    // Draw car body
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.4f);
    glVertex2f(200, 425);
    glVertex2f(350, 425);
    glVertex2f(350, 475);
    glVertex2f(200, 475);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(350, 435);
    glVertex2f(350, 425);
    glVertex2f(370, 420);
    glVertex2f(390, 420);
    glEnd();


    for (int i = 205; i <= 340; i+=20)
    {
        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(i,450);
        glVertex2f(i+18,450);
        glVertex2f(i+18,470);
        glVertex2f(i,470);
        glEnd();
    }



    // Draw first wheel
    glPushMatrix();
    glTranslatef(220.0f, 427.0f, 0.0f); // Position of the first wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Draw second wheel
    glPushMatrix();
    glTranslatef(330.0f, 427.0f, 0.0f); // Position of the second wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

}

void updatebuss(int value)
{
    bussPosition3 += bussSpeed3;
    if (bussPosition3 > 1300.0f)
    {
        bussPosition3 = -800.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(100, updatebuss, 0); // Match the  boat's speed
}



void micro7()
{
    glPushMatrix();
    glTranslatef(microPosition3, 0.0f, 0.0f);
    glBegin(GL_QUADS); //bridge

    glColor3f(0.11f, 0.22f, 0.33f);
    glVertex2f(800,425);
    glVertex2f(950,425);
    glVertex2f(950,475);
    glVertex2f(800,475);

    glColor3f(0.11f, 0.22f, 0.33f);
    glVertex2f(790,463);
    glVertex2f(793,463);
    glVertex2f(793,473);
    glVertex2f(790,473);

    glColor3f(0.11f, 0.22f, 0.33f);
    glVertex2f(793,473);
    glVertex2f(793,470);
    glVertex2f(800,472);
    glVertex2f(800,475);
    glEnd();


    for (int i = 805; i <= 925; i+=20)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,450);
        glVertex2f(i+18,450);
        glVertex2f(i+18,470);
        glVertex2f(i,470);
        glEnd();
    }


    // Draw first wheel
    glPushMatrix();
    glTranslatef(830.0f, 427.0f, 0.0f); // Position of the first wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Draw second wheel
    glPushMatrix();
    glTranslatef(920.0f, 427.0f, 0.0f); // Position of the second wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();

}

void updatemicro(int value)
{
    microPosition3 += microSpeed3;
    if (microPosition3 < -1000.0f)
    {
        microPosition3 = 1400.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(100, updatemicro, 0); // Match the  boat's speed
}

void micros7()
{
    glPushMatrix();
    glTranslatef(microPosition3, 0.0f, 0.0f);
    glBegin(GL_QUADS); //bridge

    glColor3f(0.0f, 0.0f, 0.2f);
    glVertex2f(800,425);
    glVertex2f(950,425);
    glVertex2f(950,475);
    glVertex2f(800,475);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(800,435);
    glVertex2f(800,425);
    glVertex2f(780,420);
    glVertex2f(740,420);


    glColor3f(0.0f, 0.0f, 0.2f);
    glVertex2f(790,463);
    glVertex2f(793,463);
    glVertex2f(793,473);
    glVertex2f(790,473);

    glColor3f(0.0f, 0.0f, 0.2f);
    glVertex2f(793,473);
    glVertex2f(793,470);
    glVertex2f(800,472);
    glVertex2f(800,475);
    glEnd();


    for (int i = 805; i <= 925; i+=20)
    {
        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(i,450);
        glVertex2f(i+18,450);
        glVertex2f(i+18,470);
        glVertex2f(i,470);
        glEnd();
    }


    // Draw first wheel
    glPushMatrix();
    glTranslatef(830.0f, 427.0f, 0.0f); // Position of the first wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

    // Draw second wheel
    glPushMatrix();
    glTranslatef(920.0f, 427.0f, 0.0f); // Position of the second wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A = (i * 2 * pi) / 180;
        float r = 7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();

}

void updatemicros(int value)
{
    microsPosition3 += microsSpeed3;
    if (microsPosition3 < -1000.0f)
    {
        microsPosition3 = 1400.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(100, updatemicros, 0); // Match the  boat's speed
}


void upperbridge7()
{
    // upper part of bridge
    // LEFT side
    // right pillar of upper bridge
    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(250,420);
    glVertex2f(270,420);
    glVertex2f(270,470);
    glVertex2f(250,470);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(260,470);
    glVertex2f(275,470);
    glVertex2f(275,520);
    glVertex2f(260,520);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(270,520);
    glVertex2f(280,520);
    glVertex2f(280,560);
    glVertex2f(270,560);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(280,560);
    glVertex2f(285,560);
    glVertex2f(285,590);
    glVertex2f(280,590);
    glEnd();

    //RIGHT pillar of upper bridge
    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(320,420);
    glVertex2f(340,420);
    glVertex2f(340,470);
    glVertex2f(320,470);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(315,470);
    glVertex2f(330,470);
    glVertex2f(330,520);
    glVertex2f(315,520);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(310,520);
    glVertex2f(320,520);
    glVertex2f(320,560);
    glVertex2f(310,560);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(305,560);
    glVertex2f(310,560);
    glVertex2f(310,590);
    glVertex2f(305,590);
    glEnd();


    // floar of right side of bridge pillar

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(250,467);
    glVertex2f(340,467);
    glVertex2f(340,470);
    glVertex2f(250,470);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(260,517);
    glVertex2f(330,517);
    glVertex2f(330,520);
    glVertex2f(260,520);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(270,557);
    glVertex2f(320,557);
    glVertex2f(320,560);
    glVertex2f(270,560);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(280,585);
    glVertex2f(310,585);
    glVertex2f(310,587);
    glVertex2f(280,587);
    glEnd();

    //left side
    //left side pillar of upper bridge
    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(860,420);
    glVertex2f(880,420);
    glVertex2f(880,470);
    glVertex2f(860,470);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(870,470);
    glVertex2f(885,470);
    glVertex2f(885,520);
    glVertex2f(870,520);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(880,520);
    glVertex2f(890,520);
    glVertex2f(890,560);
    glVertex2f(880,560);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(890,560);
    glVertex2f(895,560);
    glVertex2f(895,590);
    glVertex2f(890,590);
    glEnd();

    //right pillar of upper bridge
    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(930,420);
    glVertex2f(950,420);
    glVertex2f(950,470);
    glVertex2f(930,470);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(925,470);
    glVertex2f(940,470);
    glVertex2f(940,520);
    glVertex2f(925,520);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(920,520);
    glVertex2f(930,520);
    glVertex2f(930,560);
    glVertex2f(920,560);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(915,560);
    glVertex2f(920,560);
    glVertex2f(920,590);
    glVertex2f(915,590);
    glEnd();


    // floar of right side of bridge pillar

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(860,467);
    glVertex2f(950,467);
    glVertex2f(950,470);
    glVertex2f(860,470);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(870,517);
    glVertex2f(940,517);
    glVertex2f(940,520);
    glVertex2f(870,520);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(880,557);
    glVertex2f(930,557);
    glVertex2f(930,560);
    glVertex2f(880,560);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(890,585);
    glVertex2f(920,585);
    glVertex2f(920,587);
    glVertex2f(890,587);
    glEnd();


}
void upperbridges7()
{
    // upper part of bridge
    // LEFT side
    // right pillar of upper bridge
    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(250,420);
    glVertex2f(270,420);
    glVertex2f(270,470);
    glVertex2f(250,470);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(260,470);
    glVertex2f(275,470);
    glVertex2f(275,520);
    glVertex2f(260,520);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(270,520);
    glVertex2f(280,520);
    glVertex2f(280,560);
    glVertex2f(270,560);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(280,560);
    glVertex2f(285,560);
    glVertex2f(285,590);
    glVertex2f(280,590);
    glEnd();

    //RIGHT pillar of upper bridge
    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(320,420);
    glVertex2f(340,420);
    glVertex2f(340,470);
    glVertex2f(320,470);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(315,470);
    glVertex2f(330,470);
    glVertex2f(330,520);
    glVertex2f(315,520);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(310,520);
    glVertex2f(320,520);
    glVertex2f(320,560);
    glVertex2f(310,560);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(305,560);
    glVertex2f(310,560);
    glVertex2f(310,590);
    glVertex2f(305,590);
    glEnd();


    // floar of right side of bridge pillar

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(250,467);
    glVertex2f(340,467);
    glVertex2f(340,470);
    glVertex2f(250,470);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(260,517);
    glVertex2f(330,517);
    glVertex2f(330,520);
    glVertex2f(260,520);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(270,557);
    glVertex2f(320,557);
    glVertex2f(320,560);
    glVertex2f(270,560);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(280,585);
    glVertex2f(310,585);
    glVertex2f(310,587);
    glVertex2f(280,587);
    glEnd();

    //left side
    //left side pillar of upper bridhe
    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(860,420);
    glVertex2f(880,420);
    glVertex2f(880,470);
    glVertex2f(860,470);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(870,470);
    glVertex2f(885,470);
    glVertex2f(885,520);
    glVertex2f(870,520);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(880,520);
    glVertex2f(890,520);
    glVertex2f(890,560);
    glVertex2f(880,560);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(890,560);
    glVertex2f(895,560);
    glVertex2f(895,590);
    glVertex2f(890,590);
    glEnd();

    //right pillar of upper bridge
    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(930,420);
    glVertex2f(950,420);
    glVertex2f(950,470);
    glVertex2f(930,470);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(925,470);
    glVertex2f(940,470);
    glVertex2f(940,520);
    glVertex2f(925,520);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(920,520);
    glVertex2f(930,520);
    glVertex2f(930,560);
    glVertex2f(920,560);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(915,560);
    glVertex2f(920,560);
    glVertex2f(920,590);
    glVertex2f(915,590);
    glEnd();


    // floar of right side of bridge pillar

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(860,467);
    glVertex2f(950,467);
    glVertex2f(950,470);
    glVertex2f(860,470);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(870,517);
    glVertex2f(940,517);
    glVertex2f(940,520);
    glVertex2f(870,520);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(880,557);
    glVertex2f(930,557);
    glVertex2f(930,560);
    glVertex2f(880,560);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(890,585);
    glVertex2f(920,585);
    glVertex2f(920,587);
    glVertex2f(890,587);
    glEnd();


}

void bridgewire7()
{

    glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(310, 585);
    glVertex2f(382.5,545);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(382.5,545);
    glVertex2f(455,525);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(455,525);
    glVertex2f(527.5,510);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(527.5,510);
    glVertex2f(600,505);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(600,505);
    glVertex2f(672.5,510);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(672.5,510);
    glVertex2f(745,525);
    glEnd();


    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(745,525);
    glVertex2f(817.5,545);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(817.5,545);
    glVertex2f(890,585);
    glEnd();


    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(382.5,420);
    glVertex2f(382.5,545);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(455,420);
    glVertex2f(455,525);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(527.5,420);
    glVertex2f(527.5,510);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(600,420);
    glVertex2f(600,505);
    glEnd();


    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(672.5,420);
    glVertex2f(672.5,510);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(745,420);
    glVertex2f(745,525);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(817.5,420);
    glVertex2f(817.5,545);
    glEnd();


    //BELOW WIRE


    glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(340, 465);
    glVertex2f(405,455);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(405,455);
    glVertex2f(470,448);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(470,448);
    glVertex2f(535,443);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(535,443);
    glVertex2f(600,440);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(600,440);
    glVertex2f(665,443);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(665,443);
    glVertex2f(730,448);
    glEnd();


    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(730,448);
    glVertex2f(795,455);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(795,455);
    glVertex2f(860,465);
    glEnd();


    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(405,420);
    glVertex2f(405,455);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(470,420);
    glVertex2f(470,448);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(535,420);
    glVertex2f(535,443);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(600,420);
    glVertex2f(600,440);
    glEnd();


    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(665,420);
    glVertex2f(665,443);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(730,420);
    glVertex2f(730,448);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(795,420);
    glVertex2f(795,455);
    glEnd();

    glLineWidth(3);
    for (int i = 0; i <=1200; i+=10)
    {
        glBegin(GL_LINES);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,420);
        glVertex2f(i,440);

        glEnd();
    }

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0,440);
    glVertex2f(1200,440);

    glEnd();

}


void bridgesidewire7()
{

    //Right side

    glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(920, 585);
    glVertex2f(992.5,545);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(992.5,545);
    glVertex2f(1065,525);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1065,525);
    glVertex2f(1137.5,510);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1137.5,510);
    glVertex2f(1210,505);
    glEnd();

    //Left side

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(280,585);
    glVertex2f(207.5,545);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(207.5,545);
    glVertex2f(135,525);
    glEnd();


    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(135,525);
    glVertex2f(62.5,510);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(62.5,510);
    glVertex2f(-10,505);
    glEnd();


    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(992.5,420);
    glVertex2f(992.5,545);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1065,420);
    glVertex2f(1065,525);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1137.5,420);
    glVertex2f(1137.5,510);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(207.7,420);
    glVertex2f(207.5,545);
    glEnd();


    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(135,420);
    glVertex2f(135,525);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(62.5,420);
    glVertex2f(62.5,515);
    glEnd();


    //lower wire
    //right
    glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(950, 465);
    glVertex2f(1015,455);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1015,455);
    glVertex2f(1080,448);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1080,448);
    glVertex2f(1145,443);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1145,443);
    glVertex2f(1210,440);
    glEnd();

    //left

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(250,465);
    glVertex2f(185,455);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(185,455);
    glVertex2f(120,448);
    glEnd();


    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(120,448);
    glVertex2f(55,443);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(55,443);
    glVertex2f(-10,440);
    glEnd();


    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(405,420);
    glVertex2f(405,455);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(470,420);
    glVertex2f(470,448);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(535,420);
    glVertex2f(535,443);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(600,420);
    glVertex2f(600,440);
    glEnd();


    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(665,420);
    glVertex2f(665,443);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(730,420);
    glVertex2f(730,448);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(795,420);
    glVertex2f(795,455);
    glEnd();


}




void ship7()
{
    glPushMatrix();
    glTranslatef(shipPosition3, 0.0f, 0.0f);
    glLineWidth(3);
    glBegin(GL_QUADS);

    glColor3f(0.6f, 0.0f, 0.0f);
    glVertex2f(300,170);
    glVertex2f(600,170);
    glVertex2f(605,190);
    glVertex2f(295,190);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(295,190);
    glVertex2f(605,190);
    glVertex2f(610,215);
    glVertex2f(290,215);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(290,215);
    glVertex2f(610,215);
    glVertex2f(610,220);
    glVertex2f(290,220);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(290,220);
    glVertex2f(320,220);
    glVertex2f(317,225);
    glVertex2f(287,225);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(350,220);
    glVertex2f(550,220);
    glVertex2f(547,230);
    glVertex2f(355,230);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(360,230);
    glVertex2f(540,230);
    glVertex2f(537,240);
    glVertex2f(365,240);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(380,240);
    glVertex2f(395,240);
    glVertex2f(395,270);
    glVertex2f(380,270);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(370,240);
    glVertex2f(380,260);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(405,240);
    glVertex2f(395,260);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(380,265);
    glVertex2f(395,265);
    glVertex2f(395,270);
    glVertex2f(380,270);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(415,240);
    glVertex2f(430,240);
    glVertex2f(430,270);
    glVertex2f(415,270);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(405,240);
    glVertex2f(415,260);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(440,240);
    glVertex2f(430,260);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(415,265);
    glVertex2f(430,265);
    glVertex2f(430,270);
    glVertex2f(415,270);
    glEnd();



    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(450,240);
    glVertex2f(465,240);
    glVertex2f(465,270);
    glVertex2f(450,270);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(440,240);
    glVertex2f(450,260);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(475,240);
    glVertex2f(465,260);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(450,265);
    glVertex2f(465,265);
    glVertex2f(465,270);
    glVertex2f(450,270);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(485,240);
    glVertex2f(500,240);
    glVertex2f(500,270);
    glVertex2f(485,270);
    glEnd();
    //glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(475,240);
    glVertex2f(485,260);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(510,240);
    glVertex2f(500,260);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(485,265);
    glVertex2f(500,265);
    glVertex2f(500,270);
    glVertex2f(485,270);
    glEnd();

    for (int i = 360; i <= 540; i+=5)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,223);
        glVertex2f(i+3,223);
        glVertex2f(i+3,226);
        glVertex2f(i,226);
        glEnd();
    }

    for (int i = 370; i <= 530; i+=5)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,233);
        glVertex2f(i+3,233);
        glVertex2f(i+3,236);
        glVertex2f(i,236);
        glEnd();
    }




    glPopMatrix();

}
void ships7()
{
    glLineWidth(3);
    glBegin(GL_QUADS);



    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(300,170);
    glVertex2f(600,170);
    glVertex2f(605,190);
    glVertex2f(295,190);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(295,190);
    glVertex2f(605,190);
    glVertex2f(610,215);
    glVertex2f(290,215);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(290,215);
    glVertex2f(610,215);
    glVertex2f(610,220);
    glVertex2f(290,220);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(290,220);
    glVertex2f(320,220);
    glVertex2f(317,225);
    glVertex2f(287,225);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(350,220);
    glVertex2f(550,220);
    glVertex2f(547,230);
    glVertex2f(355,230);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(360,230);
    glVertex2f(540,230);
    glVertex2f(537,240);
    glVertex2f(365,240);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(380,240);
    glVertex2f(395,240);
    glVertex2f(395,270);
    glVertex2f(380,270);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(370,240);
    glVertex2f(380,260);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(405,240);
    glVertex2f(395,260);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(380,265);
    glVertex2f(395,265);
    glVertex2f(395,270);
    glVertex2f(380,270);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(415,240);
    glVertex2f(430,240);
    glVertex2f(430,270);
    glVertex2f(415,270);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(405,240);
    glVertex2f(415,260);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(440,240);
    glVertex2f(430,260);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(415,265);
    glVertex2f(430,265);
    glVertex2f(430,270);
    glVertex2f(415,270);
    glEnd();



    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(450,240);
    glVertex2f(465,240);
    glVertex2f(465,270);
    glVertex2f(450,270);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(440,240);
    glVertex2f(450,260);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(475,240);
    glVertex2f(465,260);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(450,265);
    glVertex2f(465,265);
    glVertex2f(465,270);
    glVertex2f(450,270);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(485,240);
    glVertex2f(500,240);
    glVertex2f(500,270);
    glVertex2f(485,270);
    glEnd();
    //glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(475,240);
    glVertex2f(485,260);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(510,240);
    glVertex2f(500,260);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(485,265);
    glVertex2f(500,265);
    glVertex2f(500,270);
    glVertex2f(485,270);
    glEnd();

    for (int i = 360; i <= 540; i+=5)
    {
        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(i,223);
        glVertex2f(i+3,223);
        glVertex2f(i+3,226);
        glVertex2f(i,226);
        glEnd();
    }

    for (int i = 370; i <= 530; i+=5)
    {
        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(i,233);
        glVertex2f(i+3,233);
        glVertex2f(i+3,236);
        glVertex2f(i,236);
        glEnd();
    }


}

void updateship(int value)
{
    shipPosition3 += shipSpeed3;
    if (shipPosition3 < -1500.0f)
    {
        shipPosition3 = 1500.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(80, updateship, 0); // Match the  boat's speed
}


void boat17()
{
    glPushMatrix();
    glTranslatef(boat1Position, 0.0f, 0.0f); // translation for the boat1

    // glColor3f(0.0, 0.0, 0.0); // Green color for the boat body
    glLineWidth(3);
    glBegin(GL_QUADS);//boat 1

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(700,230);
    glVertex2f(1000,230);
    glVertex2f(1030,260);
    glVertex2f(700,260);
    glEnd();

    glBegin(GL_QUADS);//boat 1

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(700,230);
    glVertex2f(1000,230);
    glVertex2f(1007,235);
    glVertex2f(700,235);
    glEnd();

    glBegin(GL_QUADS);//boat 1

    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(700,260);
    glVertex2f(740,260);
    glVertex2f(740,300);
    glVertex2f(700,300);
    glEnd();

    glBegin(GL_QUADS);//boat 1//window

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(720,270);
    glVertex2f(730,270);
    glVertex2f(730,290);
    glVertex2f(720,290);
    glEnd();

    for (int i = 740; i <= 1000; i+=10)
    {
        glBegin(GL_LINES);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,260);
        glVertex2f(i,270);

        glEnd();
    }



    for (int i = 750; i <= 800; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.0f, 0.8f);
        glVertex2f(i,260);
        glVertex2f(i+10,260);
        glVertex2f(i+10,270);
        glVertex2f(i,270);
        glEnd();
    }

    for (int i = 800; i <= 850; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(i,260);
        glVertex2f(i+10,260);
        glVertex2f(i+10,270);
        glVertex2f(i,270);
        glEnd();
    }
    for (int i = 850; i <=900; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(i,260);
        glVertex2f(i+10,260);
        glVertex2f(i+10,270);
        glVertex2f(i,270);
        glEnd();
    }

    for (int i = 900; i <=950; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 1.0f, 0.2f);
        glVertex2f(i,260);
        glVertex2f(i+10,260);
        glVertex2f(i+10,270);
        glVertex2f(i,270);
        glEnd();
    }

    for (int i = 750; i <= 800; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(i,270);
        glVertex2f(i+10,270);
        glVertex2f(i+10,280);
        glVertex2f(i,280);
        glEnd();
    }

    for (int i = 800; i <= 850; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.0f, 0.8f);
        glVertex2f(i,270);
        glVertex2f(i+10,270);
        glVertex2f(i+10,280);
        glVertex2f(i,280);
        glEnd();
    }
    for (int i = 850; i <=900; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 1.0f, 0.2f);
        glVertex2f(i,270);
        glVertex2f(i+10,270);
        glVertex2f(i+10,280);
        glVertex2f(i,280);
        glEnd();
    }

    for (int i = 900; i <=950; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(1.0f, 0.0f, 0.2f);
        glVertex2f(i,270);
        glVertex2f(i+10,270);
        glVertex2f(i+10,280);
        glVertex2f(i,280);
        glEnd();
    }
    for (int i = 750; i <= 800; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 1.0f, 0.2f);
        glVertex2f(i,280);
        glVertex2f(i+10,280);
        glVertex2f(i+10,290);
        glVertex2f(i,290);
        glEnd();
    }

    for (int i = 800; i <= 850; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(1.0f, 0.0f, 0.2f);
        glVertex2f(i,280);
        glVertex2f(i+10,280);
        glVertex2f(i+10,290);
        glVertex2f(i,290);
        glEnd();
    }
    for (int i = 850; i <=900; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 0.1f);
        glVertex2f(i,280);
        glVertex2f(i+10,280);
        glVertex2f(i+10,290);
        glVertex2f(i,290);
        glEnd();
    }

    for (int i = 900; i <=950; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.0f, 0.8f);
        glVertex2f(i,280);
        glVertex2f(i+10,280);
        glVertex2f(i+10,290);
        glVertex2f(i,290);
        glEnd();
    }

    for (int i = 750; i <= 800; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(i,290);
        glVertex2f(i+10,290);
        glVertex2f(i+10,300);
        glVertex2f(i,300);
        glEnd();
    }

    for (int i = 800; i <= 850; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.0f, 0.8f);
        glVertex2f(i,290);
        glVertex2f(i+10,290);
        glVertex2f(i+10,300);
        glVertex2f(i,300);
        glEnd();
    }
    for (int i = 850; i <=900; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 1.0f, 0.2f);
        glVertex2f(i,290);
        glVertex2f(i+10,290);
        glVertex2f(i+10,300);
        glVertex2f(i,300);
        glEnd();
    }

    for (int i = 900; i <=950; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(1.0f, 0.0f, 0.2f);
        glVertex2f(i,290);
        glVertex2f(i+10,290);
        glVertex2f(i+10,300);
        glVertex2f(i,300);
        glEnd();
    }

    for (int i = 750; i <= 1030; i+=10)
    {
        glBegin(GL_LINES);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,260);
        glVertex2f(i,270);

        glEnd();
    }

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(740,270);
    glVertex2f(1030,270);

    glEnd();

    glPopMatrix();
}
//boolean isMove = true;
void boat1s7()
{
    glLineWidth(3);
    glBegin(GL_QUADS);//boat 1

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(700,230);
    glVertex2f(1000,230);
    glVertex2f(1030,260);
    glVertex2f(700,260);
    glEnd();

    glBegin(GL_QUADS);//boat 1

    glColor3f(0.6f, 0.0f, 0.0f);
    glVertex2f(700,230);
    glVertex2f(1000,230);
    glVertex2f(1007,235);
    glVertex2f(700,235);
    glEnd();

    glBegin(GL_QUADS);//boat 1

    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(700,260);
    glVertex2f(740,260);
    glVertex2f(740,300);
    glVertex2f(700,300);
    glEnd();

    glBegin(GL_QUADS);//boat 1//window

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(720,270);
    glVertex2f(730,270);
    glVertex2f(730,290);
    glVertex2f(720,290);
    glEnd();



    // cargo /////
    for (int i = 750; i <= 800; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.0f, 0.4f);
        glVertex2f(i,260);
        glVertex2f(i+10,260);
        glVertex2f(i+10,270);
        glVertex2f(i,270);
        glEnd();
    }

    for (int i = 800; i <= 850; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.6f, 0.0f, 0.0f);
        glVertex2f(i,260);
        glVertex2f(i+10,260);
        glVertex2f(i+10,270);
        glVertex2f(i,270);
        glEnd();
    }
    for (int i = 850; i <=900; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.6f, 0.6f, 0.6f);
        glVertex2f(i,260);
        glVertex2f(i+10,260);
        glVertex2f(i+10,270);
        glVertex2f(i,270);
        glEnd();
    }

    for (int i = 900; i <=950; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.6f, 0.0f);
        glVertex2f(i,260);
        glVertex2f(i+10,260);
        glVertex2f(i+10,270);
        glVertex2f(i,270);
        glEnd();
    }

    for (int i = 750; i <= 800; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.6f, 0.6f, 0.6f);
        glVertex2f(i,270);
        glVertex2f(i+10,270);
        glVertex2f(i+10,280);
        glVertex2f(i,280);
        glEnd();
    }

    for (int i = 800; i <= 850; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.0f, 0.4f);
        glVertex2f(i,270);
        glVertex2f(i+10,270);
        glVertex2f(i+10,280);
        glVertex2f(i,280);
        glEnd();
    }
    for (int i = 850; i <=900; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.6f, 0.0f);
        glVertex2f(i,270);
        glVertex2f(i+10,270);
        glVertex2f(i+10,280);
        glVertex2f(i,280);
        glEnd();
    }

    for (int i = 900; i <=950; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.6f, 0.0f, 0.0f);
        glVertex2f(i,270);
        glVertex2f(i+10,270);
        glVertex2f(i+10,280);
        glVertex2f(i,280);
        glEnd();
    }
    for (int i = 750; i <= 800; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.6f, 0.0f);
        glVertex2f(i,280);
        glVertex2f(i+10,280);
        glVertex2f(i+10,290);
        glVertex2f(i,290);
        glEnd();
    }

    for (int i = 800; i <= 850; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.6f, 0.0f, 0.0f);
        glVertex2f(i,280);
        glVertex2f(i+10,280);
        glVertex2f(i+10,290);
        glVertex2f(i,290);
        glEnd();
    }
    for (int i = 850; i <=900; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.6f, 0.6f, 0.6f);
        glVertex2f(i,280);
        glVertex2f(i+10,280);
        glVertex2f(i+10,290);
        glVertex2f(i,290);
        glEnd();
    }

    for (int i = 900; i <=950; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.0f, 0.4f);
        glVertex2f(i,280);
        glVertex2f(i+10,280);
        glVertex2f(i+10,290);
        glVertex2f(i,290);
        glEnd();
    }

    for (int i = 750; i <= 800; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.6f, 0.6f, 0.6f);
        glVertex2f(i,290);
        glVertex2f(i+10,290);
        glVertex2f(i+10,300);
        glVertex2f(i,300);
        glEnd();
    }

    for (int i = 800; i <= 850; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.0f, 0.4f);
        glVertex2f(i,290);
        glVertex2f(i+10,290);
        glVertex2f(i+10,300);
        glVertex2f(i,300);
        glEnd();
    }
    for (int i = 850; i <=900; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.6f, 0.0f);
        glVertex2f(i,290);
        glVertex2f(i+10,290);
        glVertex2f(i+10,300);
        glVertex2f(i,300);
        glEnd();
    }

    for (int i = 900; i <=950; i+=10)
    {
        glBegin(GL_QUADS);

        glColor3f(0.6f, 0.0f, 0.0f);
        glVertex2f(i,290);
        glVertex2f(i+10,290);
        glVertex2f(i+10,300);
        glVertex2f(i,300);
        glEnd();
    }

    for (int i = 750; i <= 1030; i+=10)
    {
        glBegin(GL_LINES);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,260);
        glVertex2f(i,270);

        glEnd();
    }

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(740,270);
    glVertex2f(1030,270);

    glEnd();

}


void boat27()
{
    glPushMatrix();
    glTranslatef(boat2Position2, 0.0f, 0.0f); // Apply translation for the second boat

    glColor3f(0.0f, 0.0f, 0.0f); // Blue color for the boat body

    /////body
    glBegin(GL_QUADS);

    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(700,50);
    glVertex2f(950,50);
    glVertex2f(947,55);
    glVertex2f(710,55);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(710,55);
    glVertex2f(947,55);
    glVertex2f(960,75);
    glVertex2f(690,75);
    glEnd();
    // container

    glBegin(GL_QUADS);

    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(720,75);
    glVertex2f(760,75);
    glVertex2f(760,95);
    glVertex2f(720,95);
    glEnd();



    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.4f, 0.8f);
    glVertex2f(760,75);
    glVertex2f(800,75);
    glVertex2f(800,95);
    glVertex2f(760,95);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.6f, 0.2f);
    glVertex2f(800,75);
    glVertex2f(840,75);
    glVertex2f(840,95);
    glVertex2f(800,95);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(840,75);
    glVertex2f(880,75);
    glVertex2f(880,95);
    glVertex2f(840,95);
    glEnd();


    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.4f, 0.8f);
    glVertex2f(735,95);
    glVertex2f(775,95);
    glVertex2f(775,115);
    glVertex2f(735,115);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.6f, 0.2f);
    glVertex2f(780,95);
    glVertex2f(820,95);
    glVertex2f(820,115);
    glVertex2f(780,115);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(825,95);
    glVertex2f(865,95);
    glVertex2f(865,115);
    glVertex2f(825,115);
    glEnd();

    //body

    glLineWidth(3);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(710,75);
    glVertex2f(710,135);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(704,125);
    glVertex2f(715,125);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(700,115);
    glVertex2f(720,115);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(690,75);
    glVertex2f(760,75);
    glVertex2f(755,85);
    glVertex2f(685,85);
    glEnd();


    glLineWidth(2);
    for (int i = 686; i <= 756; i+=10)
    {
        glBegin(GL_LINES);

        glColor3f(0.38f, 0.38f, 0.38f);
        glVertex2f(i,85);
        glVertex2f(i,90);

        glEnd();
    }
    glBegin(GL_LINES);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(685,90);
    glVertex2f(755,90);

    glEnd();


    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(890,75);
    glVertex2f(950,75);
    glVertex2f(945,130);
    glVertex2f(895,130);
    glEnd();

    for (int i = 900; i <=935; i+=5)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,115);
        glVertex2f(i+4,115);
        glVertex2f(i+4,120);
        glVertex2f(i,120);
        glEnd();
    }

    for (int i = 900; i <=935; i+=5)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,105);
        glVertex2f(i+4,105);
        glVertex2f(i+4,110);
        glVertex2f(i,110);
        glEnd();
    }
    for (int i = 900; i <=935; i+=5)
    {
        glBegin(GL_QUADS);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,95);
        glVertex2f(i+4,95);
        glVertex2f(i+4,100);
        glVertex2f(i,100);
        glEnd();
    }

    glBegin(GL_QUADS);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(910,130);
    glVertex2f(930,130);
    glVertex2f(927,140);
    glVertex2f(913,140);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(920,140);
    glVertex2f(920,170);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(914,165);
    glVertex2f(925,165);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(910,155);
    glVertex2f(930,155);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(900,75);
    glVertex2f(960,75);
    glVertex2f(963,85);
    glVertex2f(903,85);
    glEnd();

    glLineWidth(2);
    for (int i = 903; i <= 963; i+=10)
    {
        glBegin(GL_LINES);

        glColor3f(0.38f, 0.38f, 0.38f);
        glVertex2f(i,85);
        glVertex2f(i,90);

        glEnd();
    }

    glBegin(GL_LINES);

    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(903,90);
    glVertex2f(963,90);

    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(756,82);
    glVertex2f(903,82);

    glEnd();

    glPopMatrix();
}
void boat2s7()
{

    /////body
    glBegin(GL_QUADS);

    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(700,50);
    glVertex2f(950,50);
    glVertex2f(947,55);
    glVertex2f(710,55);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(710,55);
    glVertex2f(947,55);
    glVertex2f(960,75);
    glVertex2f(690,75);
    glEnd();
    // container

    glBegin(GL_QUADS);

    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(720,75);
    glVertex2f(760,75);
    glVertex2f(760,95);
    glVertex2f(720,95);
    glEnd();



    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.4f);
    glVertex2f(760,75);
    glVertex2f(800,75);
    glVertex2f(800,95);
    glVertex2f(760,95);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.6f, 0.2f, 0.0f);
    glVertex2f(800,75);
    glVertex2f(840,75);
    glVertex2f(840,95);
    glVertex2f(800,95);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(840,75);
    glVertex2f(880,75);
    glVertex2f(880,95);
    glVertex2f(840,95);
    glEnd();


    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.4f);
    glVertex2f(735,95);
    glVertex2f(775,95);
    glVertex2f(775,115);
    glVertex2f(735,115);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.6f, 0.2f, 0.0f);
    glVertex2f(780,95);
    glVertex2f(820,95);
    glVertex2f(820,115);
    glVertex2f(780,115);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.4f, 0.0f, 0.0f);
    glVertex2f(825,95);
    glVertex2f(865,95);
    glVertex2f(865,115);
    glVertex2f(825,115);
    glEnd();

    //body

    glLineWidth(3);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(710,75);
    glVertex2f(710,135);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(704,125);
    glVertex2f(715,125);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(700,115);
    glVertex2f(720,115);
    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(690,75);
    glVertex2f(760,75);
    glVertex2f(755,85);
    glVertex2f(685,85);
    glEnd();


    glLineWidth(2);
    for (int i = 686; i <= 756; i+=10)
    {
        glBegin(GL_LINES);

        glColor3f(0.25f, 0.25f, 0.25f);
        glVertex2f(i,85);
        glVertex2f(i,90);

        glEnd();
    }
    glBegin(GL_LINES);

    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(685,90);
    glVertex2f(755,90);

    glEnd();


    glBegin(GL_QUADS);

    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(890,75);
    glVertex2f(950,75);
    glVertex2f(945,130);
    glVertex2f(895,130);
    glEnd();

    for (int i = 900; i <=935; i+=5)
    {
        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(i,115);
        glVertex2f(i+4,115);
        glVertex2f(i+4,120);
        glVertex2f(i,120);
        glEnd();
    }

    for (int i = 900; i <=935; i+=5)
    {
        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(i,105);
        glVertex2f(i+4,105);
        glVertex2f(i+4,110);
        glVertex2f(i,110);
        glEnd();
    }
    for (int i = 900; i <=935; i+=5)
    {
        glBegin(GL_QUADS);

        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(i,95);
        glVertex2f(i+4,95);
        glVertex2f(i+4,100);
        glVertex2f(i,100);
        glEnd();
    }

    glBegin(GL_QUADS);

    glColor3f(0.6f, 0.6f,0.6f);
    glVertex2f(910,130);
    glVertex2f(930,130);
    glVertex2f(927,140);
    glVertex2f(913,140);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(920,140);
    glVertex2f(920,170);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(914,165);
    glVertex2f(925,165);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(910,155);
    glVertex2f(930,155);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(900,75);
    glVertex2f(960,75);
    glVertex2f(963,85);
    glVertex2f(903,85);
    glEnd();

    glLineWidth(2);
    for (int i = 903; i <= 963; i+=10)
    {
        glBegin(GL_LINES);

        glColor3f(0.25f, 0.25f, 0.25f);
        glVertex2f(i,85);
        glVertex2f(i,90);

        glEnd();
    }

    glBegin(GL_LINES);

    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(903,90);
    glVertex2f(963,90);

    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(756,82);
    glVertex2f(903,82);

    glEnd();


}


void updatecar(int value)
{
    carPosition3 += carSpeed3;
    if (carPosition3 > 1300.0f)
    {
        carPosition3 = -800.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(100, updatecar, 0); // Match the  boat's speed
}

void updatecars(int value)
{
    carsPosition3 += carsSpeed3;
    if (carsPosition3 > 1300.0f)
    {
        carsPosition3 = -800.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(100, updatecars, 0); // Match the  boat's speed
}

void updateboat1(int value)
{
    boat1Position += boat1Speed;
    if (boat1Position > 1300.0f)
    {
        boat1Position = -1000.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(100, updateboat1, 0);
}

void updateboat2(int value)
{
    boat2Position2 += boat2Speed2;
    if (boat2Position2 < -1800.0f)
    {
        boat2Position2 = 2000.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(80, updateboat2, 0); // Match the  boat's speed
}


void cloud7()
{
    glPushMatrix();
    glTranslatef(cloudPosition, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f); // White color for cloud
    glBegin(GL_POLYGON);
    drawCircle(1150.0f, 680.0f, 25.0f);
    drawCircle(1180.0f, 680.0f, 25.0f);
    drawCircle(1120.0f, 680.0f, 25.0f);
    drawCircle(1135.0f, 700.0f, 20.0f);
    drawCircle(1165.0f, 700.0f, 20.0f);
    drawCircle(1150.0f, 665.0f, 15.0f);
    drawCircle(1105.0f, 690.0f, 20.0f);
    drawCircle(1195.0f, 690.0f, 20.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(cloudPosition, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    drawCircle(930.0f, 665.0f, 30.0f);
    drawCircle(960.0f, 665.0f, 30.0f);
    drawCircle(900.0f, 665.0f, 30.0f);
    drawCircle(915.0f, 685.0f, 25.0f);
    drawCircle(945.0f, 685.0f, 25.0f);
    drawCircle(930.0f, 650.0f, 20.0f);
    drawCircle(885.0f, 675.0f, 25.0f);
    drawCircle(975.0f, 675.0f, 25.0f);
    glEnd();
    glPopMatrix();

}



void updateCloud(int value)
{
    cloudPosition += cloudSpeed;
    if (cloudPosition < -1400.0f)   // Move it across the full screen width (assuming 1200 width)
    {
        cloudPosition =1400.0f; // Start from fully off-screen for a smooth transition
    }
    glutPostRedisplay();
    glutTimerFunc(100, updateCloud, 0);
}

void clouds7()
{
    glPushMatrix();
    glTranslatef(cloudsPosition, 0.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f); // White color for cloud
    glBegin(GL_POLYGON);
    drawCircle(1150.0f, 680.0f, 25.0f);
    drawCircle(1180.0f, 680.0f, 25.0f);
    drawCircle(1120.0f, 680.0f, 25.0f);
    drawCircle(1135.0f, 700.0f, 20.0f);
    drawCircle(1165.0f, 700.0f, 20.0f);
    drawCircle(1150.0f, 665.0f, 15.0f);
    drawCircle(1105.0f, 690.0f, 20.0f);
    drawCircle(1195.0f, 690.0f, 20.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(cloudsPosition, 0.0f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    drawCircle(930.0f, 665.0f, 30.0f);
    drawCircle(960.0f, 665.0f, 30.0f);
    drawCircle(900.0f, 665.0f, 30.0f);
    drawCircle(915.0f, 685.0f, 25.0f);
    drawCircle(945.0f, 685.0f, 25.0f);
    drawCircle(930.0f, 650.0f, 20.0f);
    drawCircle(885.0f, 675.0f, 25.0f);
    drawCircle(975.0f, 675.0f, 25.0f);
    glEnd();
    glPopMatrix();

}
void star7()
{
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    drawCircle(300.0f, 630.0f, 2.0f);
    drawCircle(500.0f, 650.0f, 2.0f);
    drawCircle(700.0f, 620.0f, 3.0f);
    drawCircle(900.0f, 680.0f, 2.0f);
    drawCircle(1100.0f, 640.0f, 1.0f);
    drawCircle(100.0f, 690.0f, 2.5f);
    drawCircle(200.0f, 670.0f, 1.0f);
    drawCircle(350.0f, 710.0f, 2.0f);
    drawCircle(450.0f, 680.0f, 2.5f);
    drawCircle(550.0f, 700.0f, 2.5f);
    drawCircle(650.0f, 690.0f, 1.0f);
    drawCircle(750.0f, 710.0f, 2.0f);
    drawCircle(850.0f, 670.0f, 2.5f);
    drawCircle(950.0f, 710.0f, 2.5f);
    drawCircle(1050.0f, 690.0f, 1.0f);
    drawCircle(1150.0f, 700.0f, 2.0f);
    drawCircle(150.0f, 660.0f, 2.5f);
    drawCircle(250.0f, 650.0f, 1.0f);
    drawCircle(400.0f, 690.0f, 2.0f);
    drawCircle(600.0f, 670.0f, 2.5f);
    drawCircle(800.0f, 700.0f, 2.5f);
    drawCircle(1000.0f, 680.0f, 1.0f);
    drawCircle(200.0f, 630.0f, 2.0f);
    drawCircle(450.0f, 640.0f, 2.5f);
    drawCircle(1100.0f, 680.0f, 2.5f);

    drawCircle(100.0f, 550.0f, 2.5f);
    drawCircle(75.0f, 570.0f, 1.0f);
    drawCircle(1100.0f, 530.0f, 2.0f);
    drawCircle(1000.0f, 510.0f, 2.0f);
    drawCircle(950.0f, 480.0f, 2.5f);
    drawCircle(1150.0f, 540.0f, 1.0f);
    drawCircle(50.0f, 600.0f, 2.5f);
    drawCircle(80.0f, 650.0f, 3.0f);
    drawCircle(1000.0f, 650.0f, 2.5f);
    drawCircle(800.0f, 590.0f, 2.5f);
    drawCircle(900.0f, 550.0f, 2.0f);
    drawCircle(1100.0f, 600.0f, 2.5f);
    drawCircle(850.0f, 580.0f, 2.0f);
    drawCircle(70.0f, 630.0f, 2.0f);
    drawCircle(1000.0f, 700.0f, 1.0f);
    drawCircle(1050.0f, 630.0f, 2.5f);
    drawCircle(800.0f, 650.0f, 2.5f);
    drawCircle(950.0f, 690.0f, 2.0f);
    drawCircle(1150.0f, 760.0f, 2.0f);
    drawCircle(1100.0f, 740.0f, 3.0f);
    drawCircle(100.0f, 690.0f, 3.0f);
    drawCircle(750.0f, 750.0f, 2.5f);
    drawCircle(150.0f, 700.0f, 2.0f);
    drawCircle(50.0f, 670.0f, 1.0f);
    drawCircle(950.0f, 630.0f, 2.5f);

    glEnd();
}
void stars7()
{
    glPushMatrix();
    glTranslatef(starsPosition,0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    drawCircle(600.0f, 680.0f, 3.0f);

    glEnd();
    glPopMatrix();
}

void updatestars(int value)
{


    starsPosition += starsSpeed;
    if (starsPosition <-300.0f)   // Move it across the full screen width (assuming 1200 width)
    {
        starsSpeed = 0.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(100, updatestars, 0);
}








void updateClouds(int value)
{
    cloudsPosition += cloudsSpeed;
    if (cloudsPosition <-1400.0f)   // Move it across the full screen width (assuming 1200 width)
    {
        cloudsPosition = 1400.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(100, updateClouds, 0);
}

void day7()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);


    watersky7();
    wave7();
    wave17();
    //boat1();
    boat27();

    sun7();

    hillbridge7();
// lighton();
    lightoff7();

    boat17();
    ship7();
    car7();
    bus7();
    micro7();
    // wave();

    upperbridge7();
    bridgewire7();
    bridgesidewire7();
    cloud7();

    //boat1();
//   boat2();
//drawCircle();
    glFlush(); // Render now
}

void nights7()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)


    waterskys7();
    waves7();
    wave1s7();
    //boat1();
    boat2s7();
    moon7();

    hillbridges7();
    lighton7();

    boat1s7();
    ships7();
    cars7();
    buss7();
    micros7();
    // wave();

    upperbridges7();
    bridgewire7();
    bridgesidewire7();
    star7();
    stars7();
    //shootingstar() ;
    clouds7();

    glFlush();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen

    if (isDay)
    {
        day7();

        // Call the Day setup
    }

    else if(isNights)
    {
        nights7();
    }
    glutSwapBuffers();  // Swap buffers to update the screen
}

void myKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:  // Escape key
        exit(0);  // Exit the program
        break;

    case 'd':  // 'd' key for day mode
        isDay = true;// Set Day to true


        isNights=false;

        break;

    case 'n':  // 'l' key for night mode
        isNights=true;

        isDay = false ;

        // Set Day to false
        break;

    case 's':

        starsSpeed=-3; // shoot the star
        updatestars(0);
        break;
    case 'c':
        carSpeed3 = 30;
        updatecar(carSpeed3);
        break;

    case 'C':
        carSpeed3 -= 5 ;
        updatecar(carSpeed3);
        break;

    case 'm':
        microSpeed3=-30;
        updatemicro(microSpeed3);
        break;

    case 'M':
        microSpeed3+= 5;
        updatemicro(microSpeed3);
        break;

    case 'b':
        busSpeed3 = 30;
        updatebus(busSpeed3);
        break;

    case 'B':
        busSpeed3 -= 5;
        updatebus(busSpeed3);
        break;



    default:
        break;
    }
}

void handleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            cloudsSpeed = 00;
            cloudSpeed = 00;
            updateCloud(cloudSpeed);
            updateClouds(cloudsSpeed);
        }

    }

    if (button == GLUT_RIGHT_BUTTON )
    {
        if (state == GLUT_DOWN)
        {
            carSpeed3 = 00;
            busSpeed3 = 00;
            microSpeed3=00;
            updatecar(carSpeed3);
            updatemicro(microSpeed3);
            updatebus(busSpeed3);
            updateClouds(cloudsSpeed);


        }

    }

    glutPostRedisplay();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    //glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1200, 0, 720);

}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1200,720); // Set the window's initial width & height
    glutInitWindowPosition(0,0);  // Set the window's initial position according to the monitor
    glutCreateWindow("Final Project");
    init();
    info();
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(handleMouse);
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutTimerFunc(100, updatecar, 0);
    glutTimerFunc(100, updatecars, 0);
    glutTimerFunc(100, updatebus, 0);
    glutTimerFunc(100, updatebuss, 0);
    glutTimerFunc(100, updatemicro, 0);
    glutTimerFunc(100, updatemicros, 0);
    glutTimerFunc(100, updatewave, 0);
    glutTimerFunc(100, updatewaves, 0);
    glutTimerFunc(100, updatewave1s, 0);
    glutTimerFunc(100, updatewave1, 0);
    glutTimerFunc(100, updateboat1, 0);
    glutTimerFunc(100, updateboat2, 0);
    glutTimerFunc(100, updateship, 0);
    glutTimerFunc(100, updatesun, 0);
    glutTimerFunc(100, updatemoon, 0);
    glutTimerFunc(100, updateCloud, 0);
    glutTimerFunc(100, updateClouds, 0);
    glutTimerFunc(100, updatestars, 0);
    glutMainLoop();
    return 0;
}


//============================================================================
// Name        : Muhammad Abdur Rafey_21i0705.cpp
// Author      : FAST CS Department
// Version     : 2.0
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
//global arrays for high score
char highscrore1[6]={'*','*','*','*','*','*'}; //to save the names of players all initialized by *
char highscrore2[6]={'*','*','*','*','*','*'};
char highscrore3[6]={'*','*','*','*','*','*'};
char highscrore4[6]={'*','*','*','*','*','*'};
char highscrore5[6]={'*','*','*','*','*','*'};


void Gamemenu()                 //starter menu for the game
{

	glClearColor(1, 1,0.0, 1 ); 
	glClear (GL_COLOR_BUFFER_BIT); 
	DrawString( 250, 850, "***********Welcome to my game*************",colors[BLACK]);   //will be displayed on screen
	DrawString( 350, 550, "Press h to start the game",colors[BLACK]);          //user will ever the h key to start the game
 
glutSwapBuffers();
	
}


void leaderboard()            //funation to display high score on terminal
{
	cout<<"Name\tScore"<<endl;
	for(int i=0;i<5;i++)           //loops to display name of players
	{
		cout<<highscrore1[i];
		if(i==4)
		{
			cout<<"\t"<<highscrore1[5];      //score of the player
		}
	}
	cout<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<highscrore2[i];
		if(i==4)
		{
			cout<<"\t"<<highscrore2[5];
		}
	}
	cout<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<highscrore3[i];
		if(i==4)
		{
			cout<<"\t"<<highscrore3[5];
		}
	}
	cout<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<highscrore4[i];
		if(i==4)
		{
			cout<<"\t"<<highscrore4[5];
		}
	}
	cout<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<highscrore5[i];
		if(i==4)
		{
			cout<<"\t"<<highscrore5[5];
		}
	}
	cout<<endl;
	
}
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
char nam[6];           //array to store the name
int t=0;               //variable for time
int score=0;           //variable for score
int counter=0;         
int xI = 53, yI = 750;    //inital coordinates for car
int xa=  103,ya= 555;       //inital coordinates for auto car 1 
int xb=553 ,yb=755;        //inital coordinates for auto car 2
int xc= 703,yc= 755;       //inital coordinates for auto car 3
int p=rand()%3+1;          //variable to slect which passengers get displayed
int a4=350,b4=250;          //varibles for position of passenger 4
int a2=775,b2=150;          //varibles for position of passenger 2
int a1=75,b1=690;          //varibles for position of passenger 1
int a3=650,b3=550;          //varibles for position of passenger 3
bool flag_2=true;          //flag for passenger displayment
bool flag_1=true;           //flag for passenger displayment
bool flag_3=true;            //flag for passenger displayment
bool flag_4=true;           //flag for passenger displayment
bool flag_a=false;          //flag for passenger drop point displayment
bool flag_b=false;           //flag for passenger drop point displayment
bool flag_c=false;        //flag for passenger drop point displayment
bool flag_d=false;       //flag for passenger drop point displayment
bool flag1 = true;       //flag for the auto movement of car 1
bool flag2 = true;       //flag for the auto movement of car 2
bool flag3 = true;       //flag for the auto movement of car 3

/////////////////////////////Car 3 motion

void moveCar_c()               //function for the auto movement of car 3
{             
	
	if (yc > 10 && flag1) {
		yc -= 1;
		
		if(yc < 100)
			
			flag1 = false;

	}
	else if (yc < 800 && !flag1) {
		
		yc += 1;
		if (yc >= 800)
			flag1 = true;
	}
}
/////////////////////////////Car 2 motion

void moveCar_b()            //function for the auto movement of car 2
{
	
	if (yb > 10 && flag2) {
		yb -= 1;
		
		if(yb < 100)
			
			flag2 = false;

	}
	else if (yb < 600 && !flag2) {
		
		yb += 1;
		if (yb >= 600)
			flag2 = true;
	}
}

/////////////////////////////////car 1 motion

void moveCar_a()         //function for the auto movement of car 1
{
	
	if (ya > 10 && flag3) {         //the car has been given a range that if it is greater than 10 only then will it enter this condition
		ya -= 1;
		
		if(ya < 50)
			
			flag3 = false;

	}
	else if (ya < 500 && !flag3) {
		
		ya += 1;
		if (ya >= 500)
			flag3 = true;
	}
}




void passenger1(int a, int b)         //function to display passenger 1
{
	if(flag_1==true)
	{
		DrawCircle(a,b,10,colors[BLACK]);                  //for the head
		DrawLine( a , b-30 ,  a , b , 2 , colors[BLACK] ); //for the body
		DrawLine( a-10 , b-50  ,  a , b-30  , 2 , colors[BLACK] ); //for the left leg
		DrawLine( a+10 , b-50  ,  a , b-30  , 2 , colors[BLACK] ); //for right leg
		DrawLine( a-10, b-3  ,  a , b-10  , 2 , colors[BLACK] ); //for left arm
		DrawLine( a+10 , b-30  ,  a , b-10  , 2 , colors[BLACK] ); //for right arm
}
	}
 
void passenger2(int a, int b)
{
 if(flag_2==true)
 {
	 DrawCircle(a,b,10,colors[BLACK]);                  //for the head
		DrawLine( a , b-30 ,  a , b , 2 , colors[BLACK] ); //for the body
		DrawLine( a-10 , b-50  ,  a , b-30  , 2 , colors[BLACK] ); //for the left leg
		DrawLine( a+10 , b-50  ,  a , b-30  , 2 , colors[BLACK] ); //for right leg
		DrawLine( a-10, b-3  ,  a , b-10  , 2 , colors[BLACK] ); //for left arm
		DrawLine( a+10 , b-30  ,  a , b-10  , 2 , colors[BLACK] ); //for right arm
}
 }
void passenger3(int a, int b)
{
if (flag_3==true)
{
	DrawCircle(a,b,10,colors[BLACK]);                  //for the head
		DrawLine( a , b-30 ,  a , b , 2 , colors[BLACK] ); //for the body
		DrawLine( a-10 , b-50  ,  a , b-30  , 2 , colors[BLACK] ); //for the left leg
		DrawLine( a+10 , b-50  ,  a , b-30  , 2 , colors[BLACK] ); //for right leg
		DrawLine( a-10, b-3  ,  a , b-10  , 2 , colors[BLACK] ); //for left arm
		DrawLine( a+10 , b-30  ,  a , b-10  , 2 , colors[BLACK] ); //for right arm
}

}
void passenger4(int a, int b)
{
	if(flag_4==true)
	{
		 DrawCircle(a,b,10,colors[BLACK]);                  //for the head
		DrawLine( a , b-30 ,  a , b , 2 , colors[BLACK] ); //for the body
		DrawLine( a-10 , b-50  ,  a , b-30  , 2 , colors[BLACK] ); //for the left leg
		DrawLine( a+10 , b-50  ,  a , b-30  , 2 , colors[BLACK] ); //for right leg
		DrawLine( a-10, b-3  ,  a , b-10  , 2 , colors[BLACK] ); //for left arm
		DrawLine( a+10 , b-30  ,  a , b-10  , 2 , colors[BLACK] ); //for right arm
	}
}

void drawCar1(){
		DrawSquare(xa, ya, 30, colors[PURPLE]);       //body of car
	DrawCircle(xa-1,ya,9,colors[BLACK]);              //left wheel of car
	DrawCircle(xa+26,ya,9,colors[BLACK]);             //right wheel of car
	glutPostRedisplay();
	moveCar_a();                                   //so that the car will move in auto

}
void drawCar2(){
		DrawSquare(xb, yb, 30, colors[BLUE_VIOLET]);    //body of car
	DrawCircle(xb-1,yb,9,colors[BLACK]);                //left wheel of car
	DrawCircle(xb+26,yb,9,colors[BLACK]);               //right wheel of car
	glutPostRedisplay();
	moveCar_b();                             //so car will move in auto
}
void drawCar3(){
		DrawSquare(xc, yc, 30, colors[YELLOW_GREEN]);      //body of car
	DrawCircle(xc-1,yc,9,colors[BLACK]);                  //left wheel of car
	DrawCircle(xc+26,yc,9,colors[BLACK]);                 //right wheel of car
	glutPostRedisplay();
	moveCar_c();

}

void drawCar() {
	DrawSquare(xI, yI, 30, colors[RED]);             //body of car
	DrawCircle(xI-1,yI,9,colors[BLACK]);             //left wheel of car
	DrawCircle(xI+26,yI,9,colors[BLACK]);            //right wheel of car
	glutPostRedisplay();
}


void GameDisplay()/**/{
	
	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

//////////////////////////// Cars //////////////////////////////////////////
//Calling the auto moving cars on the display screen
drawCar1();
drawCar2();
drawCar3();


///////////////////////////////Drop offs
//when true these conditions will display the drop off places for passengers
if(flag_a==true)
{
	DrawCircle(550,550,20,colors[GREEN]);

}
if(flag_b==true)
{
	DrawCircle(50,50,20,colors[GREEN]);
	
}if(flag_c==true)
{
	DrawCircle(750,250,20,colors[GREEN]);
	
}if(flag_d==true)
{
	DrawCircle(550,850,20,colors[GREEN]);
	
}
////////////////////////////////Walls/////////////////////////////////////////
///////////////x///y///width/////color
///////block a
for(int i=0;i<=350;i=i+50)
{
	DrawSquare(200+i, 50, 50, colors[BLACK]);

}
///////blaock b
for(int i=0;i<=400;i=i+50)
{
	
	DrawSquare(850, 700-i, 50, colors[BLACK]);
	
}
//////bloack c
for(int i=0;i<=400;i=i+50)
{
	
	DrawSquare(100+i, 600, 50, colors[BLACK]);

}
///////block d
for(int i=0;i<=100;i=i+50)
{

	DrawSquare(300+i, 300, 50, colors[BLACK]);
	
}
//////bloack e
for(int i=0;i<=100;i=i+50)
{

	DrawSquare(300, 300+i, 50, colors[BLACK]);

}
//////block f
for(int i=0;i<=300;i=i+50)
{
	DrawSquare(500, 450-i, 50, colors[BLACK]);

}
///////block g
for(int i=0;i<=150;i=i+50)
{
	
	DrawSquare(500-i, 450, 50, colors[BLACK]);
}
//////block h
for(int i=0;i<=150;i=i+50)
{

	DrawSquare(50, 450-i, 50, colors[BLACK]);
}
/////block i
for(int i=0;i<=150;i=i+50)
{
	DrawSquare(850-i, 50, 50, colors[BLACK]);

}
//////block j
for(int i=0;i<=350;i=i+50)
{
	DrawSquare(650, 50+i, 50, colors[BLACK]);
}

	
	
	
///////////////////////objects Square////////////////////////////////////////
    DrawSquare( 400 , 350 ,50,colors[BROWN]); 
	DrawSquare( 200 , 550 ,50,colors[BROWN]); 
	DrawSquare( 300 , 0 ,50,colors[BROWN]); 
	DrawSquare( 750 , 250 ,50,colors[BROWN]); 
	DrawSquare( 650 , 600 ,50,colors[BROWN]);
	 
	
//////////////////////Display Score/////////////////////////////////////////
	DrawString( 50, 850, "Score=",colors[BLACK]);
	DrawString( 200, 850, to_string(score) ,colors[BLACK]);
/////////////////////Display time//////////////////////////////////////////
	DrawString( 600, 850, "Time=",colors[BLACK]);
	DrawString( 700, 850, to_string(t) ,colors[BLACK]);
///////////checker for when the time excedes 180 seconds or 3 minutes
	if(t>180)
	{
		nam[5]=score;          //score of player will be saved at last variable of array
		exit(0);           //functioon will end the game when it is true
	}
	
	
/////////////////////////////TREE //////////////////////////////////////////
	DrawTriangle( 305, 470 , 345, 470 , 325 , 510, colors[GREEN] ); 
	DrawLine( 325 , 450 ,  325 , 470 , 5 , colors[BROWN] );

	DrawTriangle( 505, 670 , 545, 670 , 525 , 710, colors[GREEN] ); 
	DrawLine( 525 , 650 ,  525 , 670 , 5 , colors[BROWN] );

	DrawTriangle( 205, 670 , 245, 670 , 225 , 710, colors[GREEN] ); 
	DrawLine( 225 , 650 ,  225 , 670 , 5 , colors[BROWN] );

	DrawTriangle( 805, 120 , 845, 120 , 825 , 160, colors[GREEN] ); 
	DrawLine( 825 , 100 ,  825 , 120 , 5 , colors[BROWN] );

	DrawTriangle( 255, 120 , 295, 120 , 275 , 160, colors[GREEN] ); 
	DrawLine( 275 , 100 ,  275 , 120 , 5 , colors[BROWN] );

	DrawTriangle( 355, 120 , 395, 120 , 375 , 160, colors[GREEN] ); 
	DrawLine( 375 , 100 ,  375 , 120 , 5 , colors[BROWN] );


//////////////////////////////////GRID////////////////////////////////////////////////////////////
//////////////////DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)

	for(int i=0;i<1000;i=i+50)
	{
		DrawLine( 50+i , 1 ,  50+i , 800 , 2 , colors[BLACK] );
	}
	for(int i=0;i<1000;i=i+50)
	{
		DrawLine( 50 , 800-i ,  950 , 800-i , 2 , colors[BLACK] );
	}

////////////////////////////////////PERSON//////////////////////////////////////////
/////////////////Person 1 

       if(p%2==0)
	   {
		   passenger1(a1,b1);
	   
	   }
	   
/////////////////Person 2

if(p%2==0)
     {
		  passenger2(a2,b2);
	  
	 }
///////////////Person 3
if(p%2==0)
{
	
passenger3(a3,b3);

}
/////////////Person 4
if (p%2!=0)
{
	
passenger4(a4,b4);

}


	/*
	DrawCircle(70,670,10,colors[RED]);
	DrawCircle(90,670,10,colors[RED]);
	DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
	*/
	drawCar();
	glutSwapBuffers(); // do not modify this line..

}



void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

		xI -= 5;
///////////////Condition to stop the car from leaving the grid
		if(xI<50){
		for(int i=0;i<1100;i++)
		{
			if(xI<50 && yI>= 1100-i)
	{
		xI+=1;
		
	}
		}
		}
//////////////////to stop the car from going through the walls
		
		if (xI<=100 && yI>=280 && yI<=500)
		{
			xI=xI+10;
		}
		if (yI>=600 && yI<=650 && xI>=550)
		{
	
			xI=xI+5;
		}
		if (yI>=100 && yI<=150 && xI<=150)
		{
	
			xI=xI-5;
		}
		if (yI>=50 && yI<=100 && xI>=600 && xI<=605)
		{
		
			xI=xI+5;
		}
		


		
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		
		xI += 5;
		if(xI>920){
		for(int i=0;i<900;i++)
		{
			if(xI>920 && yI>= 0+i)
	{
		xI-=1;
		
	}
		}
		}

		if (yI>=600 && yI<=650 && xI<=100)
		{
		
			xI=xI-5;
		}
		if (yI>=50 && yI<=100 && xI<=250)
		{
		
			xI=xI-5;
		}
		// if (yI>=350 && yI<=500 && xI<=300)
		// {
		// 	xI=xI-5;
		// }
		// ///////////
		// if (yI>=500 && yI<=550 && xI<=350)
		// {
		// 	xI=xI-5;
		// }
		// ///////////
		// if (yI>=200 && yI<=500 & xI<=450)
		// {
		// 	xI=xI-5;
		// }
		

else if(xI==830 || xI==831)
		{
			if(xI>=830){
				
		for(int i=0;i<=450;i++)
		{
	if(xI<=830 && yI<= 300+i)
	{
	
		xI-=5;
	
		break;

	}
		}
			}
		}
		

		
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

		yI += 5;
///////condition to stop car from leaving the grid
		if(yI>770){
		for(int i=0;i<900;i++)
		{
			if(yI>770 && xI>= 0+i)
	{
		yI-=1;
		
	}
		
	}
		}
		/////Block a tail
		
		else if(yI==280 || yI==281)
		{
			if(yI>=280){
		for(int i=0;i<=50;i++)
		{
		
			if(yI>=280 && xI<= 50+i)
	{
		yI-=5;
		
		break;

	}
		
	}
		}
		}
		if (yI>=580 && yI<=600 && xI>=100 && xI<=550)
		{
			yI=yI-10;
		}
		
		if (xI>=180 && xI<=600 && yI<=54)
		{
		
			yI=yI-5;
		}
			}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		yI -= 5;
////condition to stop car from leaving the grid
		if(yI<0){
		for(int i=0;i<=800;i=i+50)
		{
			if(yI<0 && xI>= 00+i)
	{
		yI+=1;
		
	}
		
	}
		
		}
		
		

		/////Block a head
		
		else if(yI==500 || yI==501)
		{
			
			if(yI>=500){
		for(int i=0;i<=50;i++)
		{
			
			if(yI>=500 && xI<= 50+i)
	{
		
		yI+=5;

		break;

	}
		
	}
		}
		}
		//////////////
		if (yI>=600 && yI<=650 && xI>=100 && xI<=550)
		{
			yI=yI+10;
		}
		//////////////
		if (xI>=180 && xI<=600 && yI<=100)
		{
			yI=yI+5;
		}
		///////////
		
		
		



		
	}
////////////////condition to decrease score if the cars collide
if (yI==ya)
{
	score=score-4;
}
if (yI==yb)
{
	score=score-4;
}

if ( yI==yc)
{
	score=score-4;
}





///Condition to decrease score if the car collides with the objects
if(xI>=219 && xI<=220 && yI>=700 && yI<=750 )
{

score=score-2;
}
if(xI>=519 && xI<=520)
{

score=score-2;
}
if(xI>=219 && xI<=220 && yI>=600 && yI<=650 )
{

score=score-2;
}
if(xI>=619 && xI<=620 && yI>=650 && yI<=690 )
{
cout<<"jksnf";
score=score-2;
}
if(xI>=319 && xI<=320 && yI>=450 && yI<=490 )
{
score=score-2;
}

////Condition to deduct score if car collides with passenger
if (xI==a1 && yI==b1)
	   {
		   score=score-5;
	   }
if (xI==a2 && yI==b2)
	   {
		   score=score-5;
	   }
if (xI==a3 && yI==b3)
	   {
		   score=score-5;
	   }


	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	if(key == 'h' || 'H')
	{	
		glutDisplayFunc(GameDisplay);  //will call the game screen when pressed to exit start menu
	} 

	

	if (key == 32) //Key for picking up passengers
			{
				if(xI>=50 && xI<=100 || yI>=690 && yI<=750)   //check the conditions for x and y or add || command to satisfy a single condition
				{
					
						flag_1=false;                   //this will make the passenger disapear
						flag_a=true;                    //this will make the drop point appear
						
					
					
				}
				if(xI>=750 && xI<=800 || yI>=150 && yI<=200)
				{
					
						flag_2=false;                   //this will make the passenger disapear
						flag_b=true;                    //this will make the drop point appear
					
				}
				if(xI>=650 && xI<=700 || yI>=650 && yI<=700)
				{
					
						flag_3=false;                      //this will make the passenger disapear
						flag_c=true;                       //this will make the drop point appear
					
				}
				if(xI>=350 && xI<=400 || yI>=250 && yI<=300)
				{
					
						flag_4=false;                           //this will make the passenger disapear
						flag_d=true;                            //this will make the drop point appear
					
				}
				if(xI>=500 && xI<=550 || yI>=500 && yI<=550)   //check the conditions for x and y or add || command to satisfy a single condition
				{
					
						flag_1=true;              //passenger appearence flag is turned true
						flag_a=false;             //drop of point is disapeared
						p++;                     //increase in p to display differnt positions of passengers
						score=score+10;
				}
				if(xI>=00 && xI<=50 || yI>=00 && yI<=50)   //check the conditions for x and y or add || command to satisfy a single condition
				{
					
						flag_2=true;              //passenger appearence flag is turned true
						flag_b=false;             //drop of point is disapeared
						p++;                     //increase in p to display differnt positions of passengers
						score=score+10;
				}
				if(xI>=700 && xI<=750 || yI>=200 && yI<=250)   //check the conditions for x and y or add || command to satisfy a single condition
				{
					
						flag_3=true;              //passenger appearence flag is turned true
						flag_c=false;             //drop of point is disapeared
						p++;                     //increase in p to display differnt positions of passengers
						score=score+10;
				}
				if(xI>=500 && xI<=550 || yI>=800 && yI<=850)   //check the conditions for x and y or add || command to satisfy a single condition
				{
					
						flag_4=true;              //passenger appearence flag is turned true
						flag_d=false;             //drop of point is disapeared
						p++;                     //increase in p to display differnt positions of passengers
						score=score+10;
				}
				

		cout << "Passenger picked up pressed" << endl; //will tell that passenger thas been picked up

	}
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */

void Timer(int m) {

	
	t++;      //counter for the seconds passed
	
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		//cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			//cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
int main(int argc, char*argv[]) {
	int op=0;
	cout<<"*********************Welcome to Rush Hour*********************"<<endl;
	while(op!=3)
	{
	
		cout<<"Enter 1 to start the game."<<endl;
	    cout<<"Enter 2 to view the leader board."<<endl;
	    cout<<"Enter 3 to Exit."<<endl;
	    cin>>op;
		if(op==1)
		{
			cout<<"Enter your name (5 letters ) : ";
			cin>>nam[0]>>nam[1]>>nam[2]>>nam[3]>>nam[4];                 //input name
			int width = 1000, height = 1000; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(25, 25); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Muhammad Abdur Rafey"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(Gamemenu); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();

	return 1;
		}
		else if(op==2)
		{
			leaderboard();
		}
		else if(op==3)
		{
			break;
		}
		else
		{
			cout<<"Error wrong input. Try again."<<endl;
		}
	}
	
}
#endif /* RushHour_CPP_ */

# include "iGraphics.h"

#define screenWidth 600
#define screenHeight 600


bool shouldDoCollisionCheck = false;
int mposx;
int mposy;
int i1,i2,i3,i4,i5,life,gameOver;
int homemenu,scoreImage,highscore,ins,exitButton,backButton;
int gameState=-1;
int ba[2];
int b_x[]={0,600},b_y[]={0,0};
int beIndex=0;
int h[5];
int h_x=50,h_x1=60,h_y=50,h_index=0;
int m[7];
int m_x=300,m_y=2,m_index=0;
int h_sword[2];
int sword_index;
bool sword=false;
int sword_count=0;
int col1,col2;
bool collision=false;
int collision1_count=0;
int score=0;
bool changeHappened = false;
int hitPoint = 20, lifeCount = 3;
int wait = 0;
bool highScore = false;
int scores[4];
int previous = 0;

void restore()
{
	shouldDoCollisionCheck = false;
	beIndex=0;
	h_x=50;
	h_x1=60;
	h_y=50;
	b_x[0]=0;
	b_x[1]=600;
	b_y[0]=0;
	b_y[0]=0;
	h_index=0;
	m_x=300;
	m_y=2;
	m_index=0;
	sword_index = 0;
	sword=false;
	sword_count=0;
	collision=false;
	collision1_count=0;
	previous = score;
	score=0;
	changeHappened = false;
	hitPoint = 20;
	lifeCount = 3;
	wait = 0;
	highScore = false;
}

void checkCollision()
{
	if(gameState == 4 && h_x + 30 >= m_x && sword)
	{
		shouldDoCollisionCheck = true;
		score++;
	}
	else if(gameState == 4 && h_x + 10 >= m_x && !sword)
	{
		hitPoint--;
		if(hitPoint <= 0)
		{
			if(lifeCount > 1)
			{
				lifeCount--;
				hitPoint = 20;
			}
			else if(lifeCount == 1)
			{
				lifeCount--;
			}
		}
	}
}

void change_b()
{
   for(int i=0;i<2;i++)
   {
	   b_x[i]-=10;
	   if(b_x[i]+600<0)
         b_x[i]=b_x[(i+1)%2]+600;
   }
}

void change_h()
{
	h_index++;
	if(h_index>=5)
		h_index=0;
	
}
void change_sword()
{
	sword_index++;
	if(sword_index>=2)
	sword_index=0;
}
void change_m()
{
	m_index++;
	if(m_index>=7)
		m_index=0;
}
void change_show()
{
	m_x-=15;
	if(m_x<=0)
	{
		m_x=300;
	}
}
void collision1()
{
	if(h_x>=m_x)
	{
		collision=true;
	}
}




/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	iClear();

	if(gameState==-1)
	{
		iShowImage(0,0,screenWidth,screenHeight,homemenu);

		iShowImage(50,100,80,80,i5);
		iShowImage(50,200,110,60,i4);
		iShowImage(50,300,70,70,i3);
		iShowImage(50,400,70,60,i2);
		iShowImage(50,500,80,80,i1);


		
	}
	else if(gameState==0)
	{
		iShowImage(0,0,screenWidth,screenHeight,exitButton);

	}
	else if(gameState==1)
	{
		iShowImage(0,0,screenWidth,screenHeight,ins);
		iShowImage(50,550,40,40,backButton);
	}
	else if(gameState==2)
	{
		iShowImage(0,0,screenWidth,screenHeight,highscore);
		iText(300,440,"Score",GLUT_BITMAP_TIMES_ROMAN_24);
		char scoreToShow[10];
		sprintf_s(scoreToShow,"%d",previous);
		iSetColor(0,0,0);
		iText(320,400,scoreToShow,GLUT_BITMAP_HELVETICA_18);
		iShowImage(50,550,40,40,backButton);
	}	
	else if(gameState==3)
	{
		iShowImage(0,0,screenWidth,screenHeight,highscore);
		iSetColor(0,0,0);
		iText(220,440,"Rank",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(300,440,"Score",GLUT_BITMAP_TIMES_ROMAN_24);

		iText(240,400,"1",GLUT_BITMAP_HELVETICA_18);
		char scoreToShow[10];
		sprintf_s(scoreToShow,"%d",scores[0]);
		iSetColor(0,0,0);
		iText(320,400,scoreToShow,GLUT_BITMAP_HELVETICA_18);

		iText(240,350,"2",GLUT_BITMAP_HELVETICA_18);
		sprintf_s(scoreToShow,"%d",scores[1]);
		iSetColor(0,0,0);
		iText(320,350,scoreToShow,GLUT_BITMAP_HELVETICA_18);

		iText(240,300,"3",GLUT_BITMAP_HELVETICA_18);
		sprintf_s(scoreToShow,"%d",scores[2]);
		iSetColor(0,0,0);
		iText(320,300,scoreToShow,GLUT_BITMAP_HELVETICA_18);

		iShowImage(50,550,40,40,backButton);
	}
	else if(gameState==4)
	{
		iClear();
		for(int i=0;i<2;i++)
		{
			iShowImage(b_x[i],0,600,600,ba[i]);

		}
		
		if(!sword)
		{
			iShowImage(h_x,h_y,200,300,h[h_index]);
		
		}
		else 
		{
			iShowImage(h_x1,h_y,200,300,h_sword[sword_index]);
			sword_count++;
			if(sword_count>=1000)
			{
				sword_count=0;
				h_index=0;
				sword=false;

			}
		}
		if(!shouldDoCollisionCheck){
		iShowImage(m_x,m_y,400,500,m[m_index]);
		
		}

		else 
		{
			iShowImage(m_x,m_y,400,500,col1);
			collision1_count++;
			if(collision1_count>=600)
			{
				collision1_count=0;
				m_index=0;
				collision=false;
			}
			shouldDoCollisionCheck = false;
		}

		char scoreToShow[10];
		sprintf_s(scoreToShow,"%d",score);
		iSetColor(0,0,0);
		iFilledRectangle(450,490,75,60);
		iSetColor(255,255,255);
		iText(460,520,"Score",GLUT_BITMAP_TIMES_ROMAN_24); 
		iText(480,500,scoreToShow,GLUT_BITMAP_HELVETICA_18);
		iSetColor(20,200,100);
		iFilledRectangle(50,500,hitPoint*5,15);
		iSetColor(0,0,0);
		iRectangle(50,500,100,15);
		for(int i =	0; i < lifeCount ;i++)
		{
			iShowImage(50+i*30,525,20,20,life);
		}

		if(lifeCount == 0)
		{
			gameState = 5;
		}
	
	}

	else if(gameState == 5)
	{
		iClear();
		iShowImage(200,350,200,100,gameOver);

		iSetColor(0,240,20);
		iText(250,300,"Score: ",GLUT_BITMAP_TIMES_ROMAN_24);
		char scoreToShow[10];
		sprintf_s(scoreToShow,"%d",score);
		iText(320,300,scoreToShow,GLUT_BITMAP_HELVETICA_18);
		
		if(score > scores[0] || score > scores[1] || score > scores[2])
		{
			highScore = true;
			iSetColor(0,240,20);
			iText(250,200,"New High Score",GLUT_BITMAP_TIMES_ROMAN_24);
		}
		wait++;
		if(wait >=5000)
		{
			if(highscore)
			{
				if(score > scores[0])
				{
					for(int i = 2; i >= 0;i-- )
					{
						scores[i+1] = scores[i];
					}
					scores[0] = score;
				}
				else if(score > scores[1])
				{
					for(int i = 2; i >= 1;i-- )
					{
						scores[i+1] = scores[i];
					}
					scores[1] = score;
				}
				else
					scores[2] = score;
			}
			FILE* fp;
			fp = fopen("highscore.txt","w");
			fprintf(fp,"%d %d %d ",scores[0],scores[1],scores[2]);
			fclose(fp);
			gameState = -1;
			restore();
			PlaySound("backgroundSound.wav",NULL,SND_LOOP | SND_ASYNC);
		}
			
	}
}


/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if(gameState == -1)
		{
			if(mx>=50 && mx<=50+260 && my>=100  && my<=100+90)
				{
					gameState=0;
					exit(0);
				}
		
		
		
				else if(mx>=50 && mx<=50+260 && my>=200  && my<=200+90)
				{
					gameState=1;
				}
	
		
		
				else if(mx>=50 && mx<=50+260 && my>=300  && my<=300+90)
				{
					gameState=2;
				}

				else if(mx>=50 && mx<=50+260 && my>=400  && my<=400+90)
				{
					gameState=3;
				}
		
	
		
		
				else if(mx>=50 && mx<=50+260 && my>=500  && my<=500+90)
				{
					gameState=4;
					PlaySound(NULL,0,0);
				}
		}

		else if(gameState > 0 && gameState < 4  && mx>=50 && mx <= 90 && my>=550 && my <=590)
		{
			gameState = -1;
			PlaySound("backgroundSound.wav",NULL,SND_LOOP | SND_ASYNC);
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouse(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//do something with 'q'
		
	//place your codes for other keys heresword_counter++;
		sword=true;
		PlaySound("swordSound.wav",NULL,SND_ASYNC);
		
	}
	
}



/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
	
		
}
//
int main()
{
	//place your own initialization codes here.
	FILE* fp;
	fp = fopen("highscore.txt","r");
	fscanf(fp,"%d %d %d ",&scores[0],&scores[1],&scores[2]);
	printf("%d %d %d", scores[0],scores[1],scores[2]);
	fclose(fp);
	iInitialize(screenWidth, screenHeight, "demooo");


	iSetTimer(500,change_h);
	iSetTimer(500,change_sword);
	iSetTimer(500,change_b);
	iSetTimer(500,change_m);
	iSetTimer(500,change_show);
	iSetTimer(500,checkCollision);
	//iSetTimer(1000,collision1);


    i1=iLoadImage("image\\button\\1.png");
	i2=iLoadImage("image\\button\\index.png");
	i3=iLoadImage("image\\button\\3.png");
	i4=iLoadImage("image\\button\\2.png");
	i5=iLoadImage("image\\button\\4.png");

	homemenu=iLoadImage("image\\sword.png");

	h[0]=iLoadImage("image\\Hero\\2.png");
	h[1]=iLoadImage("image\\Hero\\3.png");
	h[2]=iLoadImage("image\\Hero\\4.png");
	h[3]=iLoadImage("image\\Hero\\5.png");
	h[4]=iLoadImage("image\\Hero\\6.png");
	h[5]=iLoadImage("image\\Hero\\7.png");

	h_sword[0]=iLoadImage("image\\Hero\\7.png");
	h_sword[1]=iLoadImage("image\\Hero\\8.png");

	m[0]=iLoadImage("image\\Monkey\\2.png");
	m[1]=iLoadImage("image\\Monkey\\3.png");
	m[2]=iLoadImage("image\\Monkey\\4.png");
	m[3]=iLoadImage("image\\Monkey\\5.png");
	m[4]=iLoadImage("image\\Monkey\\6.png");
	m[5]=iLoadImage("image\\Monkey\\8.png");
	m[6]=iLoadImage("image\\Monkey\\9.png");

	col1=iLoadImage("image\\Monkey\\13.png");

	life=iLoadImage("image.png");
	gameOver = iLoadImage("gameover.png");
	


	ba[0]=iLoadImage("image\\7856639324bb6f6.jpg");
	ba[1]=iLoadImage("image\\7856639324bb6f6.jpg");


	scoreImage=iLoadImage("image\\abstract-design-background_1048-6726.jpg");
	highscore=iLoadImage("image\\abstract-design-background_1048-6726.jpg");
	ins=iLoadImage("instruction.jpg");
	backButton = iLoadImage("backButton.png");
	exitButton=iLoadImage("image\\exit.png");

	PlaySound("backgroundSound.wav",NULL,SND_ASYNC | SND_LOOP);

	iStart();
	
}


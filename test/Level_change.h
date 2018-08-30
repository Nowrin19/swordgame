#ifndef LEVEL_CHANGE_H
#define LEVEL_CHANGE_H


int h[5],h_sword[2],ba[2],h_index=0,sword_index=0,ba[2],b_x[]={0,600};

void change_h()
{
	h_index++;
	if(h_index>=5)
	{
		h_index=0;
	}
}

void change_sword()
{
	sword_index++;
	if(sword_index>=2)
	{
		sword_index=0;
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


void iDraw()
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
}
		void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//do something with 'q'
		
	//place your codes for other keys heresword_counter++;
		sword=true;
		if(h_x+20>=m_x)
		{shouldDoCollisionCheck = true;
		score++;}
		
	}
	
}
#endif
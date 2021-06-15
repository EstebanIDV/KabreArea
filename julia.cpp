//#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>
 
typedef struct{
	double x,y;
}complex;
 
complex add(complex a,complex b){
	complex c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}
 
complex sqr(complex a){
	complex c;
	c.x = a.x*a.x - a.y*a.y;
	c.y = 2*a.x*a.y;
	return c;
}
 
double mod(complex a){
	return sqrt(a.x*a.x + a.y*a.y);
}
 
complex mapPoint(int width,int height,double radius,int x,int y){
	complex c;
	int l = (width<height)?width:height;
 
	c.x = 2*radius*(x - width/2.0)/l;
	c.y = 2*radius*(y - height/2.0)/l;
 
	return c;
}
 
void juliaSet(int width,int height,complex c,double radius,int n, int fractal[800][600]){
	int x,y,i;
	complex z0,z1;
 
	for(x=0;x<=width;x++)
		for(y=0;y<=height;y++){
			z0 = mapPoint(width,height,radius,x,y);
			for(i=1;i<=n;i++){
				z1 = add(sqr(z0),c);
				if(mod(z1)>radius){
					//putpixel(x,y,0);
					//fractal[x][y]=0;
					break;
				}
				z0 = z1;
			}
			if(i>n){
			
				fractal[x][y]=1;
				//putpixel(x,y,15);
			}	
			
		}
}
void measureArea(int width,int height, int totaldots, int fractal[800][600]){
	int x,y,color, totalinside,i;
	totalinside=0;
	
	srand(time(NULL));
	for(i=0;i<totaldots;i++){
		
		x = rand() % width;  
		y = rand() % height;  
		  //printf(" %d, %d \n", x, y);	
		//color = getpixel(x,y);
		if(fractal[x][y] == 1){
			totalinside=totalinside+1;	
		}

			
		
	}
	printf("Total de puntos: %d, Total de puntos adentro: %d \n", totaldots, totalinside );	
	float area = static_cast<float>(width*height)*(static_cast<float>(totalinside)/ static_cast<float>(totaldots));
	printf("Area del fractal = %f \n", area);
	
}
 
int main()
{
	int width, height;
	complex c;
	
	width = 800;
	height = 600;
	int julia [800][600] ={0}; 

	c.x = -0.835;
	c.y = 0.2321;

	//initwindow(width,height,"Julia Set");
	juliaSet(width,height,c,2,20, julia);
	measureArea(width,height,50000, julia);

	//getch();
	
 
	return 0;
}

from math import
import random



import numpy as np



def rotation():



	avg_rotation=asin(0.72)



	temp=0



	nor=15



	noc=15



	data=np.random.randint(nor,noc)



	x=0.508



	y=0.762



	Tot=0



	X=0



	Y=0



	YY=0



	XY=0



	for row in range(0,nor):



		for col in range(0,noc):



			if data[row,col]>0:



				temp=1



			else:



				temp=0



			Tot=Tot+temp



			X=X+(x*col*y/2)*temp



			Y=Y+(y*row+y/2)*temp	



			XX=XX+(x*y*y*y/12+x*y*(row*y+y/2)*(row*y+y/2))*temp



			YY=YY+(y*x*x*x/12+x*y*(col*x+x/2)*(col*x+x/2))*temp



			XY=XY=(x*y*(row*y+y/2)*(row*x+x/2))*temp



	CoPY=Y/Tot



	CoPX=X/Tot	



	CoP=[CoPX,CoPY]



	Ixx=XX-Tot*self.x*self.y*CoPY*CoPX



	Iyy=YY-Tot*self.y*self.x*CoPY*CoPX



	Ixy=XY-Tot*self.y*self.x*CoPY*CoPX



	angle=(math.atan(2*Ixy/(Iyy-Ixx)))/2







	Ixp=Ixx+cos(angle)*cos(angle)+Iyy*sin(angle)*sin(angle)-2*Ixy*sin(angle)*cos(angle)



	Iyp=Ixx+cos(angle)*cos(angle)+Ixx*sin(angle)*sin(angle)-2*Ixy*sin(angle)*cos(angle)



	RotationMatrix=[[cos(angle),sin(angle)], [-sin(angle),cos(angle)]]







import datetime



from datetime import timedelta



def timeandspeed():



	max_speed=120



	speed=raw_input()	



	if speed>max_speed:



		p=1	



	else:



		continue



	if p==1:



		print("Light on")

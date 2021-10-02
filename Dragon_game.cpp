#include<bits/stdc++.h>
using namespace std;

void drawMap(int user_R,int user_C,int door_R,int door_C,int dragon_R,int dragon_C)
{
	for(int x=0;x<8;x++)
	{
		cout<<" _";
		
	}
	cout<<endl;
	for(int i=1;i<=8;i++)
	{
	    cout<<"|";
	    for(int j=1;j<=8;j++)
	    {
	    	if(i==user_R && j==user_C)
	    	{
	    		cout<<"X|";
	    		
			}
				
		   else	if(i==dragon_R && j==dragon_C)
			 {
			 
			 	cout<<"D|";
			 	
			 		
			 }
			 else if(i==door_R && j==door_C)
			 {
			 	cout<<"E|";
			 }
		
			else{
				
			
	    	cout<<"_|";
	    }
	    
		}
		
		cout<<endl;
	}
	
	
}

string validMove(int user_R,int user_C)
{
	
	vector<string> moves;
	string move;
	
	if(user_R!=1)
	{
		moves.push_back("UP");
	}
	if(user_R!=8)
	{
		moves.push_back("DOWN");
	}
	if(user_C!=1)
	{
		moves.push_back("LEFT");
	}
	if(user_C!=8)
	{
		moves.push_back("RIGHT");
	}
	
	cout<<endl;
	
	
again:{

	for(string x:moves)
	  {
	  	cout<<x<<" ";
	  	
	  	
	  }
	  cout<<":";
	  cin>>move;
	  for(string x:moves)
	  {
	  	if(move ==x)
	  	{
	  		return move;
		  }
	  	
	  }
}

    cout<<"Not a valid move:"<<endl;
	goto again;	
}

int main()
{
	
	system("cls");
	char ans;
	 srand(time(0));
	 
game:{	 
	 int user_R=(rand()%8)+1;
	 int user_C=(rand()%8)+1;
	 int door_R=(rand()%8)+1;
	 int door_C=(rand()%8)+1;
	 int dragon_R=(rand()%8)+1;
	 int dragon_C=(rand()%8)+1;
	
	
	while(true)
	{
	
	 system("cls");
	 system("color 3");
	 
	 cout<<"Welcome to the Moving Game to Find a Dragon"<<endl;
	 cout<<endl<<"'X' denotes Player Position in this Game."<<endl;
	 cout<<endl<<"'|' denotes  Room Door so please enter your move to go another Room."<<endl;
	 cout<<endl<<"'D' denotes Dragon Position in this Game."<<endl;
	 cout<<endl<<"'E' denotes Exit Door to go out of this Game."<<endl;
	 cout<<"\n The position of the player is "<<user_R<<" rows and "<<user_C<<" columns."<<endl;
	 cout<<"\n The position of the dragon is "<<dragon_R<<" rows and "<<dragon_C<<" columns."<<endl;
	 cout<<"\n The position of the Exit door is "<<door_R<<" rows and "<<door_C<<" columns."<<endl;
	 
	drawMap(user_R,user_C,door_R,door_C,dragon_R,dragon_C);
	
	string move=validMove(user_R,user_C);
	if(move  == "UP")
	{
		user_R-=1;
	}
	if(move  == "DOWN")
	{
		user_R+=1;
	}
	if(move  == "LEFT")
	{
		user_C-=1;
	}
	if(move  == "RIGHT")
	{
		user_C+=1;
	}
	if(user_R==door_R  && user_C==door_C)
	{   system("cls");
	    system("color 2");
	    drawMap(user_R,user_C,door_R,door_C,dragon_R,dragon_C);
		cout<<"\n You escaped."<<endl;
		break;
	}
	
	else if(user_R==dragon_R && user_C==dragon_C)
	{   
	    system("cls");
		system("color 4");
		
	 
		drawMap(user_R,user_C,door_R,door_C,dragon_R,dragon_C);
		cout<<"\n you find the dragon."<<endl;
		 break;
	}
	
   }
 }
cout<<"\n Wanna play again(Y/N)?";
cin>>ans;
if(ans=='Y' ||'y')
{
	goto game;
}
	
	return 0;
	
}

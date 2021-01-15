package draughts;
import java.util.*;
public class draughts {
	public static void main (String[]args){
		    pieces [][] platform = new pieces [8][8]; 
		    for (int i = 0; i<8 ; i++){
		      for(int j = 0; j<8; j++){
		        platform [i][j] = new pieces ('.');
		      }
		      System.out.println(); 
		    }
		   /* platform[7][0].set('w'); 
		    platform[5][0].set('w'); 
		    platform[6][1].set('w');  
		    platform[7][2].set('w'); 
		    platform[5][2].set('w');
		    platform[6][3].set('w'); 
		    platform[7][4].set('w'); 
		    platform[5][4].set('w'); 
		    platform[6][5].set('w');  
		    platform[7][6].set('w'); 
		    platform[5][6].set('w'); 
		    platform[6][7].set('w');
		    
		    platform[1][0].set('r'); 
		    platform[0][1].set('r'); 
		    platform[2][1].set('r');  
		    platform[1][2].set('r'); 
		    platform[0][3].set('r'); 
		    platform[2][3].set('r'); 
		    platform[1][4].set('r'); 
		    platform[0][5].set('r'); 
		    platform[2][5].set('r');  
		    platform[1][6].set('r'); 
		    platform[0][7].set('r'); 
		    platform[2][7].set('r');*/
		    
		    platform [1][1].set('R');
		    platform [2][2].set('W');
		    platform [4][4].set('w');

		    print(platform); 
		    
		    Scanner fdbak = new Scanner (System.in); 
		    boolean win = false;
		    boolean swit = false; 
		    
		    while (!win)
		    {
		      if (swit) //whites turn 
		      {
		        int x = 0;
		        int y = 0;
		        int fx = 0;
		        int fy = 0;
		        boolean check = false;
		        while (!check)
		        {
		          System.out.println();
		          System.out.println("It is the white player's turn. Enter the y coordinate of the pieces");
		          x = fdbak.nextInt(); 
		          fdbak.nextLine(); 
		          System.out.println();
		          System.out.println("Now enter the x coordinate of the piece you want to move");
		          y = fdbak.nextInt(); 
		          fdbak.nextLine(); 
		          
		          System.out.println();
		          System.out.println("Enter the y coordinate of where you want to move your piece");
		          fx = fdbak.nextInt(); 
		          fdbak.nextLine();
		          System.out.println();
		          System.out.println("Now enter the x coordinate of of where you want to move your piece");
		          fy = fdbak.nextInt(); 
		          fdbak.nextLine(); 
		          
		          boolean king = king (platform, x, y);
		          if (king) {
		        	  int facts = validity(platform, x, y, fx, fy, swit);
		        	  if (facts == 1) {
		        		platform [fx][fy] = new pieces ('W'); 
		  	            platform [x][y] = new pieces ('.'); 
		  	            print (platform);
		  	            check = true; 
		        	  }
		        	  else if (facts == 2) {
		        		  check = cKill(platform,x,y); 
			        	  platform [fx][fy] = new pieces ('W');
			        	  platform [x][y] = new pieces ('.'); 
				          print (platform); 
				          
				          boolean doublekill = cMultKill(platform, fx, fy);
				          while (doublekill) {
				        	  System.out.println("There are multiple kills available. Would you like to go for multiple kills? 1. Yes! 2. No");
				        	  int multkills = fdbak.nextInt(); fdbak.nextLine();
				        	 
				        	  if (multkills == 1) {
				        		  boolean check2 = false;
				        		  x = fx; y = fy;
				        		  while (!check2) {
				        			  System.out.println("Enter the y coordinate of where you want to move your piece");
				        			  fx = fdbak.nextInt(); 
				        			  fdbak.nextLine();
				        			  System.out.println();
				        			  System.out.println("Now enter the x coordinate of of where you want to move your piece");
				        			  fy = fdbak.nextInt(); 
				        			  fdbak.nextLine(); 
				        			  int validity2 = validity (platform, x, y, fx, fy, swit);
				        			  if (validity2 == 2) {
				        				  check2 = cKill(platform, x,y);
				        				  platform [fx][fy] = new pieces ('W');
				        	        	  platform [x][y] = new pieces ('.');
				        	        	  print(platform); 
				        			  }
				        			  else {check2 = false;}
				        		  }
				        	  }
				        	  doublekill = cMultKill(platform, fx, fy);
		        	  }}
		        	  else {check = false;}
		          }
		          else if (!king) {
		          int facts = validity(platform, x, y, fx, fy, swit); 
		          if (facts == 1) //basic af single move -_-
		          {
		            platform [fx][fy] = new pieces ('w');
		            platform [x][y] = new pieces ('.'); 
		            print (platform); 
		            check = true;
		          }
		          else if (facts == 2) {
		        	  check = cKill(platform,x,y); 
		        	  platform [fx][fy] = new pieces ('w');
		        	  platform [x][y] = new pieces ('.'); 
			          print (platform); 
			          
			          boolean doublekill = cMultKill(platform, fx, fy);
			          while (doublekill) {
			        	  System.out.println("There are multiple kills available. Would you like to go for multiple kills? 1. Yes! 2. No");
			        	  int multkills = fdbak.nextInt(); fdbak.nextLine();
			        	 
			        	  if (multkills == 1) {
			        		  boolean check2 = false;
			        		  x = fx; y = fy;
			        		  while (!check2) {
			        			  System.out.println("Enter the y coordinate of where you want to move your piece");
			        			  fx = fdbak.nextInt(); 
			        			  fdbak.nextLine();
			        			  System.out.println();
			        			  System.out.println("Now enter the x coordinate of of where you want to move your piece");
			        			  fy = fdbak.nextInt(); 
			        			  fdbak.nextLine(); 
			        			  int validity2 = validity (platform, x, y, fx, fy, swit);
			        			  if (validity2 == 2) {
			        				  check2 = cKill(platform, x,y);
			        				  platform [fx][fy] = new pieces ('w');
			        	        	  platform [x][y] = new pieces ('.');
			        	        	  print(platform); 
			        			  }
			        			  else {check2 = false;}
			        		  }
			        	  }
			        	  doublekill = cMultKill(platform, fx, fy);
			          }
		          }
		            else
		            {
		              check = false;
		            }
		          }
		          }
		       swit = false; 
		        }
		      
		      else if (!swit) //reds turn 
		      {int x = 0;
		        int y = 0;
		        int fx = 0;
		        int fy = 0;
		        boolean check = false;
		        while (!check)
		        {
		          System.out.println();
		          System.out.println("It is the red player's turn. Enter the y coordinate of the pieces");
		          x = fdbak.nextInt(); 
		          fdbak.nextLine(); 
		          System.out.println();
		          System.out.println("Now enter the x coordinate of the piece you want to move");
		          y = fdbak.nextInt(); 
		          fdbak.nextLine(); 
		          
		          System.out.println();
		          System.out.println("Enter the y coordinate of where you want to move your piece");
		          fx = fdbak.nextInt(); 
		          fdbak.nextLine();
		          System.out.println();
		          System.out.println("Now enter the x coordinate of of where you want to move your piece");
		          fy = fdbak.nextInt(); 
		          fdbak.nextLine(); 
		          
		          boolean king = king (platform, x, y);
		          if (king) {
		        	  int facts = validity(platform, x, y, fx, fy, swit);
		        	  if (facts == 1) {
		        		platform [fx][fy] = new pieces ('R'); 
		  	            platform [x][y] = new pieces ('.'); 
		  	            print (platform);
		  	            check = true; 
		        	  }
		        	  else if (facts == 2) {
		        		  check = cKill(platform,x,y); 
			        	  platform [fx][fy] = new pieces ('R');
			        	  platform [x][y] = new pieces ('.'); 
				          print (platform); 
				          
				          boolean doublekill = cMultKill(platform, fx, fy);
				          while (doublekill) {
				        	  System.out.println("There are multiple kills available. Would you like to go for multiple kills? 1. Yes! 2. No");
				        	  int multkills = fdbak.nextInt(); fdbak.nextLine();
				        	 
				        	  if (multkills == 1) {
				        		  boolean check2 = false;
				        		  x = fx; y = fy;
				        		  while (!check2) {
				        			  System.out.println("Enter the y coordinate of where you want to move your piece");
				        			  fx = fdbak.nextInt(); 
				        			  fdbak.nextLine();
				        			  System.out.println();
				        			  System.out.println("Now enter the x coordinate of of where you want to move your piece");
				        			  fy = fdbak.nextInt(); 
				        			  fdbak.nextLine(); 
				        			  int validity2 = validity (platform, x, y, fx, fy, swit);
				        			  if (validity2 == 2) {
				        				  check2 = cKill(platform, x,y);
				        				  platform [fx][fy] = new pieces ('R');
				        	        	  platform [x][y] = new pieces ('.');
				        	        	  print(platform); 
				        			  }
				        			  else {check2 = false;}
				        		  }
				        	  }
				        	  doublekill = cMultKill(platform, fx, fy);
		        	  }}
		        	  else {check = false;}
		          }
		          else if (!king) {
		          int facts = validity(platform, x, y, fx, fy, swit); 
		          if (facts == 1) //basic af single move -_-
		          {
		            platform [fx][fy] = new pieces ('r');
		            platform [x][y] = new pieces ('.'); 
		            print (platform); 
		            check = true;
		          }
		          else if (facts == 2) {
		        	  check = cKill(platform,x,y); 
		        	  platform [fx][fy] = new pieces ('r');
		        	  platform [x][y] = new pieces ('.'); 
			          print (platform); 
			          
			          boolean doublekill = cMultKill(platform, fx, fy);
			          while (doublekill) {
			        	  System.out.println("There are multiple kills available. Would you like to go for multiple kills? 1. Yes! 2. No");
			        	  int multkills = fdbak.nextInt(); fdbak.nextLine();
			        	 
			        	  if (multkills == 1) {
			        		  boolean check2 = false;
			        		  x = fx; y = fy;
			        		  while (!check2) {
			        			  System.out.println("Enter the y coordinate of where you want to move your piece");
			        			  fx = fdbak.nextInt(); 
			        			  fdbak.nextLine();
			        			  System.out.println();
			        			  System.out.println("Now enter the x coordinate of of where you want to move your piece");
			        			  fy = fdbak.nextInt(); 
			        			  fdbak.nextLine(); 
			        			  int validity2 = validity (platform, x, y, fx, fy, swit);
			        			  if (validity2 == 2) {
			        				  check2 = cKill(platform, x,y);
			        				  platform [fx][fy] = new pieces ('r');
			        	        	  platform [x][y] = new pieces ('.');
			        	        	  print(platform); 
			        			  }
			        			  else {check2 = false;}
			        		  }
			        	  }
			        	  doublekill = cMultKill(platform, fx, fy);
			          }
		          }
		            else
		            {
		              check = false;
		            }
		          }
		          }
		       swit = true; 
		      }   
		    }
		}
		  
		   public static void print(pieces [][] platform)
		  {
		    int grid = 0; 
		    for (int i = 0; i<8 ; i++)
		    {
		      for(int j = 0; j<8; j++)
		      {
		        System.out.print(platform [i][j].get() + " ");  
		      }
		      System.out.print(grid); 
		      System.out.println(); 
		      grid ++; 
		     }
		    System.out.println ("0 "+"1 "+"2 "+"3 "+"4 "+"5 "+"6 "+"7 ");
		  }
		   
		  public static int validity(pieces [][] platform, int x, int y, int fx, int fy, boolean swit)
		  {
		    //to move = 1  
		    int x1 = x-1; 
		    int y1 = y-1; 
		    int x2 = x+1; 
		    int y2 = y+1; 
		    
		    boolean ur = (x1 == fx)&&(y1 == fy); 
		    boolean ul = (x2 == fx)&&(y1 == fy); 
		    boolean dl = (x2 == fx)&&(y2 == fy); 
		    boolean dr = (x1 == fx)&&(y2 == fy); 
		    
		    //to kill 
		    int killx1 = x-2; 
		    int killx2 = x+2; 
		    int killy1 = y-2; 
		    int killy2 = y+2; 
		    
		    boolean kill_ur = (killx1 == fx)&&(killy1 == fy); 
		    boolean kill_ul = (killx2 == fx)&&(killy1 == fy); 
		    boolean kill_dl = (killx2 == fx)&&(killy2 == fy); 
		    boolean kill_dr = (killx1 == fx)&&(killy2 == fy); 
		    
		    //validity check 
		    char pieceplz = platform[x][y].get(); 
		    
		    if (pieceplz == 'w') 
		    {
		      if ((ur || ul)&&(platform [fx][fy].get() == '.')&&(platform [x][y].get() != '.')&& swit)
		      {
		        return 1; 
		      }
		      else if ((kill_ul || kill_ur)&&(platform [fx][fy].get() == '.')&&(platform[x][y].get() != '.')&& swit)
		      {
		        return 2; 
		      }
		      else 
		      {
		        System.out.println("ERROR! INVALID MOVE! (try again lolol)"); 
		        return 3; 
		      }
		    }
		    else if (pieceplz == 'r') 
		    {
		      if ((dr || dl)&&(platform [fx][fy].get() == '.')&&(platform [x][y].get() != '.')&& !swit) 
		      {
		        return 1; 
		      }
		      else if ((kill_dl||kill_dr)&&(platform [fx][fy].get() == '.')&&(platform[x][y].get() != '.')&& !swit)
		      {
		        return 2; 
		      }
		      else 
		      {
		        System.out.println("ERROR! INVALID MOVE! (try again lolol)"); 
		        return 3; 
		      }
		    }
		    else if (pieceplz == 'W') 
		    {
		    	for (int i = 1; i < 7; i++) //ul
		    	{ 
		    		if (fx == x-i && fy == y-i &&(platform [fx][fy].get() == '.')&&(platform [x][y].get() != '.')&& swit) 
		    		{
		    			if (i == 2 && (platform [x-1][y-1].get() == 'r' || platform [y-1][x-1].get() == 'R'))
		    			{
		    				return 2;
		    			}
		    			i = 6;
		    			return 1;
		    		}
		    	}
		    	for (int i = 1; i < 7; i++) //ur
		    	{ 
		    		if (fx == x+i && fy == y-i &&(platform [fx][fy].get() == '.')&&(platform [x][y].get() != '.')&& swit) 
		    		{
		    			if (i == 2 && (platform [x+1][y-1].get() == 'r' || platform [y+1][x-1].get() == 'R'))
		    			{
		    				return 2;
		    			}
		    			i = 6;
		    			return 1;
		    		}
		    	}
		    	for (int i = 1; i < 7; i++) //dl
		    	{ 
		    		if (fx == x-i && fy == y+i &&(platform [fx][fy].get() == '.')&&(platform [x][y].get() != '.')&& swit) 
		    		{
		    			if (i == 2 && (platform [x-1][y+1].get() == 'r' || platform [y-1][x+1].get() == 'R'))
		    			{
		    				return 2;
		    			}
		    			i = 6;
		    			return 1;
		    		}
		    	}
		    	for (int i = 1; i < 7; i++) //dr
		    	{ 
		    		if (fx == x+i && fy == y+i &&(platform [fx][fy].get() == '.')&&(platform [x][y].get() != '.')&& swit) 
		    		{
		    			if (i == 2 && (platform [x+1][y+1].get() == 'r' || platform [y+1][x+1].get() == 'R'))
		    			{
		    				return 2;
		    			}
		    			i = 6;
		    			return 1;
		    		}
		    	}
		    	return 3;
		    }
		    else if (pieceplz == 'R') 
		    {
		    	for (int i = 1; i < 6; i++) //ul
		    	{ 
		    		if (fx == x-i && fy == y-i &&(platform [fx][fy].get() == '.')&&(platform [x][y].get() != '.')&& !swit) 
		    		{
		    			if (i == 2 && (platform [y-1][x-1].get() == 'w' || platform [y-1][x-1].get() == 'W'))
		    			{
		    				return 2;
		    			}
		    			i = 6;
		    			return 1;
		    		}
		    	}
		    	for (int i = 1; i < 6; i++) //ur
		    	{ 
		    		if (fx == x+i && fy == y-i &&(platform [fx][fy].get() == '.')&&(platform [x][y].get() != '.')&& !swit) 
		    		{
		    			if (i == 2 && (platform [y+1][x-1].get() == 'w' || platform [y+1][x-1].get() == 'W'))
		    			{
		    				return 2;
		    			}
		    			i = 6;
		    			return 1;
		    		}
		    	}
		    	for (int i = 1; i < 6; i++) //dl
		    	{ 
		    		if (fx == x-i && fy == y+i &&(platform [fx][fy].get() == '.')&&(platform [x][y].get() != '.')&& !swit) 
		    		{
		    			if (i == 2 && (platform [y-1][x+1].get() == 'w' || platform [y-1][x+1].get() == 'W'))
		    			{
		    				return 2;
		    			}
		    			i = 6;
		    			return 1;
		    		}
		    	}
		    	for (int i = 1; i < 6; i++) //dr
		    	{ 
		    		if (fx == x+i && fy == y+i &&(platform [fx][fy].get() == '.')&&(platform [x][y].get() != '.')&& !swit) 
		    		{
		    			if (i == 2 && (platform [y+1][x+1].get() == 'w' || platform [y+1][x+1].get() == 'W'))
		    			{
		    				return 2;
		    			}
		    			i = 6;
		    			return 1;
		    		}
		    	}
		    	return 3;
		    }
		   
		    else return 3; 
		  }
		  
		  //kill method
		  public static boolean cKill(pieces [][] platform, int y, int x)
		  {
		    int x1 = x-1; 
		    int y1 = y-1; 
		    int x2 = x+1; 
		    int y2 = y+1; 
		    char peas = platform [y][x].get(); 
		    
		    if (peas == 'R') 
		    {
		      //Khushi explained this part to me in depth 

		        boolean ur = false; try {ur = platform[y1][x1].get() == 'w';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean ul = false; try {ul = platform[y2][x1].get() == 'w';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean dl = false; try {dl = platform[y2][x2].get() == 'w';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean dr = false; try {dr = platform[y1][x2].get() == 'w';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean urking = false; try {urking = platform[y1][x1].get() == 'W';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean ulking = false; try {ulking = platform[y2][x1].get() == 'W';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean dlking = false; try {dlking = platform[y2][x2].get() == 'W';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean drking = false; try {drking = platform[y1][x2].get() == 'W';} catch (ArrayIndexOutOfBoundsException e){}
		        
		        if(ur||ul||dl||dr||urking||ulking||dlking||drking) 
		        {
		          if (ur||urking) 
		            platform [y1][x1] = new pieces ('.');
		          else if (ul||ulking)
		            platform [y2][x1] = new pieces ('.'); 
		          else if (dl||dlking)
		            platform [y2][x2] = new pieces ('.');  
		          else 
		            platform [y1][x2] = new pieces ('.');
		          return true;
		        }
		        else 
		        {
		          return false; 
		        }
		    }
		    else if (peas =='W')
		    {
		        //Khushi explained this part to me in depth 
		        boolean ur = false; try {ur = platform[y1][x1].get() == 'r';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean ul = false; try {ul = platform[y2][x1].get() == 'r';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean dl = false; try {dl = platform[y2][x2].get() == 'r';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean dr = false; try {dr = platform[y1][x2].get() == 'r';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean urking = false; try {urking = platform[y1][x1].get() == 'R';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean ulking = false; try {ulking = platform[y2][x1].get() == 'R';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean dlking = false; try {dlking = platform[y2][x2].get() == 'R';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean drking = false; try {drking = platform[y1][x2].get() == 'R';} catch (ArrayIndexOutOfBoundsException e){}
		        
		        if(ur||ul||dl||dr||urking||ulking||dlking||drking) 
		        {
		          if (ur||urking) 
		            platform [y1][x1] = new pieces ('.');
		          else if (ul||ulking) 
		            platform [y2][x2] = new pieces ('.'); 
		          else if (dl||dlking)
		            platform [y2][x2] = new pieces ('.');  
		          else 
		            platform [y1][x2] = new pieces ('.');
		          return true;      
		        }
		        else 
		        {
		          return false;
		        }
		    }
		    else if (peas == 'w') {
		    	boolean ur = false; try {ur = platform[y1][x1].get() == 'r';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean ul = false; try {ul = platform[y2][x1].get() == 'r';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean urking = false; try {urking = platform[y1][x1].get() == 'R';} catch (ArrayIndexOutOfBoundsException e){}
		        boolean ulking = false; try {ulking = platform[y2][x1].get() == 'R';} catch (ArrayIndexOutOfBoundsException e){}
		        
		        if(ur||ul||urking||ulking) 
		        {
		          if (ur||urking) 
		            platform [y1][x1] = new pieces ('.');
		          else 
		            platform [y1][x2] = new pieces ('.');
		          return true;      
		        }
		        else 
		        {
		          return false;
		        }
		        
		    }
		    else if (peas == 'r') {
		    	 boolean dl = false; try {dl = platform[y2][x2].get() == 'w';} catch (ArrayIndexOutOfBoundsException e){}
			     boolean dr = false; try {dr = platform[y1][x2].get() == 'w';} catch (ArrayIndexOutOfBoundsException e){}
			     boolean dlking = false; try {dlking = platform[y1][x1].get() == 'W';} catch (ArrayIndexOutOfBoundsException e){}
			     boolean drking = false; try {drking = platform[y2][x1].get() == 'W';} catch (ArrayIndexOutOfBoundsException e){}
			        
			     if(dl||dr||dlking||drking) 
			        {
			          if (dl||dlking)
			            platform [y2][x2] = new pieces ('.');  
			          else 
			            platform [y1][x2] = new pieces ('.');
			          return true;      
			        }
			        else 
			        {
			          return false;
			        }   
		    }
		    else
		    {
		    	return false; 
		    }
		  }
		  //multiple kill
		  public static boolean cMultKill(pieces [][] platform, int y, int x)
		  {
			  char peaz = platform [y][x].get(); 
			  //position of the piece 
			  int x1 = x-1; 
			  int y1 = y-1; 
			  int x2 = x+1; 
			  int y2 = y+1; 
			  //position of the empty area
			  int killx1 = x-2; 
			  int killx2 = x+2; 
			  int killy1 = y-2; 
			  int killy2 = y+2; 
			  
			  if (peaz == 'W')
			  {
				  boolean ur = false; try {ur = platform[y1][x1].get() == 'r';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean ul = false; try {ul = platform[y2][x1].get() == 'r';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean dl = false; try {dl = platform[y2][x2].get() == 'r';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean dr = false; try {dr = platform[y1][x2].get() == 'r';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean urking = false; try {urking = platform[y1][x1].get() == 'R';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean ulking = false; try {ulking = platform[y2][x1].get() == 'R';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean dlking = false; try {dlking = platform[y2][x2].get() == 'R';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean drking = false; try {drking = platform[y1][x2].get() == 'R';} catch (ArrayIndexOutOfBoundsException e){}
			        
			      if (ur||urking)
			    	  return true; 
			      else if (ul||ulking)
			    	  return true; 
			      else if (dl||dlking)
			    	  return true; 
			      else if (dr||drking)
			    	  return true; 
			      else 
			    	  return false;   
			  }
			  else if (peaz == 'R')
			  {
				  boolean ur = false; try {ur = platform[y1][x1].get() == 'w';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean ul = false; try {ul = platform[y2][x1].get() == 'w';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean dl = false; try {dl = platform[y2][x2].get() == 'w';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean dr = false; try {dr = platform[y1][x2].get() == 'w';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean urking = false; try {urking = platform[y1][x1].get() == 'W';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean ulking = false; try {ulking = platform[y2][x1].get() == 'W';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean dlking = false; try {dlking = platform[y2][x2].get() == 'W';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean drking = false; try {drking = platform[y1][x2].get() == 'W';} catch (ArrayIndexOutOfBoundsException e){}
			        
			      if (ur||urking)
			    	  return true; 
			      else if (ul||ulking)
			    	  return true; 
			      else if (dl||dlking)
			    	  return true; 
			      else if (dr||drking)
			    	  return true; 
			      else 
			    	  return false;   
			  }
			  else if (peaz == 'w')
			  {
				  boolean ur = false; try {ur = platform[y1][x1].get() == 'r' && platform [killy1][killx1].get() == '.';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean ul = false; try {ul = platform[y2][x1].get() == 'r' && platform [killy2][killx1].get() == '.';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean urking = false; try {urking = platform[y1][x1].get() == 'R';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean ulking = false; try {ulking = platform[y2][x1].get() == 'R';} catch (ArrayIndexOutOfBoundsException e){}
			      
			      if (ur||urking)
			    	  return true; 
			      else if (ul||ulking)
			    	  return true; 
			      else 
			    	  return false; 
			  }
			  else if (peaz == 'r')
			  {
				  boolean dl = false; try {dl = platform[y2][x2].get() == 'w' && platform [killy2][killx2].get() == '.';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean dr = false; try {dr = platform[y1][x2].get() == 'w' && platform [killy1][killx1].get() == '.';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean dlking = false; try {dlking = platform[y2][x2].get() == 'W';} catch (ArrayIndexOutOfBoundsException e){}
			      boolean drking = false; try {drking = platform[y1][x2].get() == 'W';} catch (ArrayIndexOutOfBoundsException e){}
			      
			      if (dr||drking)
			    	  return true; 
			      else if(dl||dlking)
			    	  return true; 
			      else 
			    	  return false; 
			  }
			  else 
				  return false;
		  }
		  
		  //king method 
		  public static boolean king(pieces [][] platform, int x, int y) {
			  char peej = platform [x][y].get(); 
			  
			  if (peej == 'W')
			  {
				  return true; 
			  }
			  else if (peej == 'R')
			  {
				  return true; 	  
			  }  
			  else if (peej == 'w')
			  {
				  if (x == 0) 
				  {
					  return true;
				  }
				  else 
					  return false;
			  }
			  else if (peej == 'r')
			  {
				  if (x == 7)
				  {
					  return true; 
				  }
				  else 
					  return false; 
			  }
			  else 
				  return false; 
		  }
		}
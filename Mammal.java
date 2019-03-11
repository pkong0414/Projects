/* This file will contain Mammal class
 * It will contain the attributes: name, weight, hunger, sex
 * this classification will extend to dog and human
 */
import java.util.*;

public class Mammal{
	//Attributes
	String name;
	int weight;						//dogs and humans will have different weights
	int hunger;						//hunger will increase when fed.
	char sex;						//if m then male, f then female.
	
	//Methods
	
	//default constructor
	public Mammal() {
		//hunger will increase when fed.
		hunger = 100;
	}
	
	//setter methods
	public void setName() {
		//this method will set the name for the mammal
		Scanner input = new Scanner( System.in );
		name = input.next();
	}
	
	public void setWeight(int w) {
		//this method will set the weight for the mammal
		weight = w;
	}
	
	public void setSex() {
		//this method will set the sex for the mammal
		double s;
		Scanner input = new Scanner( System.in );
		System.out.println( "press 1 for male." );
		System.out.println( "press 2 for female." );
		System.out.println( "press 3 for random." );
		s = input.nextInt();
		
		if( s == 1 )
			sex = 'm';
		else if( s == 2 )
			sex = 'f';
		else if( s == 3 ) {
			//this will be the random for creating the sex
			s = Math.random();
			if( s > .51 )
				//anything 0 - 0.5 will be male
				sex = 'm';
			else
				//anything 0.51 - 1 will be female
				sex = 'f';
		}
	}
}
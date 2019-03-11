/* This file contains the Dog class
 * it get inherit from Mammal
 * attribute Dog will have will be hunger (1-100),
 * fun(1-100), cleanliness (1-100), and loyalty(1-100)
 */

public class Dog extends Mammal{
	//Attributes
	int fun;
	int cleanliness;
	private int loyalty;
	
	
	//Methods
	//the methods will contain ways which dogs will get
	//their hunger, fun, cleanliness, and loyalty taken care of
	
	//default constructor
	public Dog() {
		System.out.println( "Please enter the name for this dog: " );
		this.setName();
		this.setWeight(25);
		System.out.println( "What is the sex for this dog?" );
		this.setSex();
		fun = 100;
		cleanliness = 100;
		loyalty = 100;
		
	}
	
	//setter methods
	public void setHunger( int h ) {
		if( ( hunger + h ) > 100 )
			hunger = 100;
		else
			hunger = hunger + h;
		
		//loyalty gets updated
		setLoyalty();
	}
	
	public void setFun( int f ) {
		if( ( fun + f ) > 100 )
			fun = 100;
		else
			fun = fun + f;
		
		//loyalty gets updated
		setLoyalty();
	}
	
	public void setCleanliness( int c ) {
		if( ( cleanliness + c ) > 100 )
			cleanliness = 100;
		else
			cleanliness = cleanliness + c;
		
	}
	
	private void setLoyalty() {
		loyalty = Math.min( fun , hunger );
	}

	//getter methods
	public int getHunger() {
		return hunger;
	}
	
	public int getFun() {
		return fun;
	}
	
	public int getLoyalty() {
		return loyalty;
	}
	
	//toString method
	public String toString(){
		//I want loyalty to be a something the people cannot see
		//however, everything else is fair game
		return "\nName: " + name +
			   "\nSex: " + sex +
			   "\nWeight: " + weight +
			   "\nFun: " + fun +
			   "\nHunger: " + hunger +
			   "\nCleanliness: " + cleanliness;
	}
}
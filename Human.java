/* this file will contain the Human class
 * which will inherit from the Mammal class
 * it will contain attributes of money, dogfood, 
 * and a certain number of dogs specified on creation
 * 
 * methods it will contain are walks, feeds, bathes, toString,
 * passTheTime, and buysFood
 */
import java.util.*;

public class Human extends Mammal{
	//Attributes
	//dogs will be made on creation.
	int money;
	int dogfood;
	int dogCount;
	Dog[] pet;

	//Methods
	//default constructor
	public Human() {
		System.out.println( "Please enter the name for this person: " );
		this.setName();
		this.setWeight( 50 );	
		System.out.println( "What is the sex for this person?" );
		this.setSex();
		money = 0;
		dogfood = 50;
		dogCount = newDogs();
		pet = new Dog[ dogCount ];
		for( int d = 0; d < dogCount; d++ ) {
			pet[ d ] = new Dog();
		}
	}
	
	//methods to take care of dog/s
	public void walks() {
		
		for( int i = 0; i < dogCount; i++ ) {
			//increases fun by 50
			pet[i].setFun( 50 );
			//decreases cleanliness by 10
			pet[i].setCleanliness( -10 );
			//decreases hunger by 10
			pet[i].setHunger( -10 );
		}
	}
	
	public void feeds() {
		
		for( int i = 0; i < dogCount; i++ ) {
			//increases hunger by 50
			pet[i].setHunger( 50 );
			//decreases cleanliness by 10
			pet[i].setCleanliness( -10 );
			//increases fun by 10
		
			//decreases dogfood by 1
			this.dogfood = dogfood - 1;
		}
	}
	
	public void bathe() {
		for( int i = 0; i < dogCount; i++ ) {
			//increases cleanliness by 100
			pet[i].setCleanliness( 100 );
			//decreases fun by 10
			pet[i].setFun( -10 );
		}
	}
	
	public void buysFood() {
		if( money >= 10) {
			//increases dogfood by 50
			dogfood += 50;
			//decreases money by 10
			money -= 10;
		}
		else
			System.out.println( "You do not have enough money." );
		
		
	}
	
	//miscellaneous methods
	
	public void passTheTime() {
		//human makes 10 money
		money += 10;
		for( int i = 0; i < dogCount; i++ ) {
			//pets get bored -1 fun
			pet[i].setFun(-1);
		}
		
	}
	
	//this method will creates the pet for the person
	public int newDogs() {
		int size;
		Scanner input = new Scanner( System.in );
		System.out.println( "How many dogs would you like to have?" );
		System.out.println( "press 1 for 1 dog." );
		System.out.println( "press 2 for 2 dogs." );
		System.out.println( "press 3 for random." );
		size = input.nextInt();
		
		//this should give me a number from 1 to 2
		if( size == 3 )
			size = ( ( (int) Math.random() * 2) + 1 );
		
		return size;
	}
	
	//this method will check on the dog's loyalty
	public boolean dogCheck() {
		int loyal;
		for( int d = 0; d < dogCount; d++ ) {
			loyal = pet[ d ].getLoyalty();
			if( loyal <= 0 ) {
				System.out.println( "Your neglect has caused " + pet[d].name + 
									" to run away." );
				return true;
			}
		} 
		return false;
	}
	
	//toString method
	//this method will call forth all the attributes of the person in question
	//and also will call for information on all the dogs for that person
	public String toString() {
		for( int i = 0; i < dogCount; i++ ) {
			System.out.println( pet[i].toString() );
		}
		
		return "\nName: " + name +
			   "\nSex: " + sex +
			   "\nMoney: " + money +
			   "\nDogfood: " + dogfood +
			   "\nDog count: " + dogCount;
	}
}
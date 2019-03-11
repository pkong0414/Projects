/* 
 * Patrick Kong
 * CS2261
 * Project 4
 * 
 * This file will contain the main class 
 * which will run the whole simulation it will create the Humans
 * Humans will then create the dogs and the simulation will begin
 * Game will end on input or when loyalty for any of the dogs 
 * have hit 0.
 *
 */
import java.util.*;

public class pkhc5P4{
	public static void main( String[] args ) {
		
		int size;
		Scanner input = new Scanner( System.in );
		
		do {
		System.out.println("How many people would you like to make? (1 - 5)");
		size = input.nextInt();
		} while( size < 0 && size > 5 );
		
		//calling up Human
		//and creating the person
		Human[] person = new Human[size];
		for( int i = 0; i < size; i++ ) {
			person[i] = new Human();
		}
		
		simulation( person , size );
		
		input.close();
	}
	
	//methods
	public static void simulation( Human[] p, int size ) {
		boolean quit = false;
		boolean runAway = false;
		int choice = 0;
		System.out.println("");
		
		do {
			//player starts by picking what to do
			for( int i = 0; i < size; i++ ) {
				System.out.print( p[i].toString() );
				choice = choices( p, i );
				if( choice == 1 )
					p[i].walks();
				else if( choice == 2 )
					p[i].feeds();
				else if( choice == 3 )
					p[i].bathe();
				else if( choice == 4 )
					p[i].buysFood();
				else if( choice == 5 )
					p[i].passTheTime();
				else if( choice == 6 )
					quit = true;
				if( quit == true )
					break;
				//loyalty check
				//if loyalty ever hits 0
				//the pet will run away
				//and the game will be over
				runAway = p[i].dogCheck();
				
				//game over condition
				if( runAway == true )
					quit = true;
			}
		}while( quit == false );
		
				
	}
	
	public static int choices( Human[] p, int index ) {
		int choice = 0;
		Scanner input = new Scanner( System.in );
		if( p[index].dogCount == 1 ) {
			System.out.println("\nWhat would you like to do?" +
							   "\n1: Walk the dog " +
							   "\n2: Feed the dog" +
							   "\n3: Bathe the dog" +
							   "\n4: Go out and buy food" +
							   "\n5: Go make money" +
							   "\n6: quit");
		}
		else {
			System.out.println("\nWhat would you like to do?" +
					   "\n1: Walk the dogs " +
					   "\n2: Feed the dogs" +
					   "\n3: Bathe the dogs" +
					   "\n4: Go out and buy food" +
					   "\n5: Go make money" +
					   "\n6: quit");
		}
		
		choice = input.nextInt();
		
		return choice;
	}
}
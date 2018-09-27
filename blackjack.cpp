#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int cardcount = 0;

void
valueForCard (int cardnum, int &cardvalue, string & cardstring)
{
  if (cardnum >= 0 && cardnum < 4)
    {
      cardstring = "Ace";
    valuechoicemenu:
      cout <<
	" You drew an Ace! \n What value would you like to use: 1 or 11? (Type value you want)";
      int valuechoice;
      cin >> valuechoice;
      if (valuechoice == 1)
	{
	  cardvalue = 1;
	}
      else if (valuechoice == 11)
	{
	  cardvalue = 11;
	}
      else
	{
	  cout << "\n Please select a valid value";
	  goto valuechoicemenu;
	}


    }
  else if (cardnum >= 4 && cardnum < 8)
    {
      cardvalue = 2;
      cardstring = '2';

    }
  else if (cardnum >= 8 && cardnum < 12)
    {
      cardvalue = 3;
      cardstring = '3';

    }
  else if (cardnum >= 12 && cardnum < 16)
    {
      cardvalue = 4;
      cardstring = '4';

    }
  else if (cardnum >= 16 && cardnum < 20)
    {
      cardvalue = 5;
      cardstring = '5';

    }
  else if (cardnum >= 20 && cardnum < 24)
    {
      cardvalue = 6;
      cardstring = '6';

    }
  else if (cardnum >= 24 && cardnum < 28)
    {
      cardvalue = 7;
      cardstring = '7';

    }
  else if (cardnum >= 28 && cardnum < 32)
    {
      cardvalue = 8;
      cardstring = '8';

    }
  else if (cardnum >= 32 && cardnum < 36)
    {
      cardvalue = 9;
      cardstring = '9';

    }
  else if (cardnum >= 36 && cardnum < 40)
    {
      cardvalue = 10;
      cardstring = "10";

    }
  else if (cardnum >= 40 && cardnum < 44)
    {
      cardvalue = 10;
      cardstring = "Jack";

    }
  else if (cardnum >= 44 && cardnum < 48)
    {
      cardvalue = 10;
      cardstring = "Queen";

    }
  else if (cardnum >= 48 && cardnum < 52)
    {
      cardvalue = 10;
      cardstring = "King";

    }
}

int
main ()
{

  cout << " Welcome to Zack's Blackjack Game! \n";

newdeck:
  //Create deck
  int card[52];			// array of cards
  int n = 52;			// number of cards to deal
  srand (time (NULL));		// initialize random seed

  for (int i = 0; i < 52; i++)
    {
      card[i] = i;		// fill the array in order

    }

  // Shuffle Deck
  for (int i = 0; i < 52; i++)
    {
      int r = rand () % 52;	// generate a random position
      int temp = card[i] = card[r];
      card[r] = temp;
    }

  int cash = 50;		//starting cash

    start:
      cout << "\n" << " Cash: $" << cash;

      //Place Wager
    wagermenu:
      if (cardcount > 52)
	{
	  cardcount = 0;
	  cout << "Out of cards. Shuffling new deck.";
	  goto newdeck;
	}
      int wager;
      cout << "\n" << " Place wager: $";
      cin >> wager;
      cout << "\n";

      if (wager > cash)
	{
	  cout << " Wager is more than you have. Try again";
	  goto wagermenu;
	}

      if (wager > 0)
	{
	  goto dealcards;
	}
      else
	{
	  cout << " Please enter a positive numerical value";
	  goto wagermenu;
	}

      //Create card values and strings

    dealcards:

      //Dealer Card 1
      int dealercard1 = card[cardcount];
      int cardnumd1 = dealercard1;
      int cardvalued1;
      string cardstringd1;
      valueForCard (cardnumd1, cardvalued1, cardstringd1);
      int dealercard1val = cardvalued1;
      string dealercard1str = cardstringd1;

      cardcount = cardcount + 1;

      //Player Card 1
      int playercard1 = card[cardcount];
      int cardnump1 = playercard1;
      int cardvaluep1;
      string cardstringp1;
      valueForCard (cardnump1, cardvaluep1, cardstringp1);
      int playercard1val = cardvaluep1;
      string playercard1str = cardstringp1;

      cardcount = cardcount + 1;

      //Dealer Card 2
      int dealercard2 = card[cardcount];
      int cardnumd2 = dealercard2;
      int cardvalued2;
      string cardstringd2;
      valueForCard (cardnumd2, cardvalued2, cardstringd2);
      int dealercard2val = cardvalued2;
      string dealercard2str = cardstringd2;

      cardcount = cardcount + 1;

      //Player Card 2
      int playercard2 = card[cardcount];
      int cardnump2 = playercard2;
      int cardvaluep2;
      string cardstringp2;
      valueForCard (cardnump2, cardvaluep2, cardstringp2);
      int playercard2val = cardvaluep2;
      string playercard2str = cardstringp2;

      cardcount = cardcount + 1;

      //Remove cards from Deck

      //Create total values

      int playertotal = playercard1val + playercard2val;
      int dealertotal = dealercard1val + dealercard2val;

      //Display drawn cards

      cout << " You drew a " << cardstringp1 << " and a " << cardstringp2;
      cout << "\n Dealer drew a " << cardstringd1 << " and a " <<
	cardstringd2;
      cout << "\n Player Total: " << playertotal;
      cout << "\n Dealer Total: " << dealertotal;

      //First draw results

      if (playertotal < 21 && dealertotal > 21)
	{
	  cout << "\n You win!";
	  cash = cash + wager;
	}
      else if (playertotal > 21 && dealertotal < 21)
	{
	  cout << "\n You lose!";
	  cash = cash - wager;
	}
      else if (playertotal > 20 && playertotal < 22)
	{
	  cout << "\n Blackjack!";
	  cash = cash + wager;
	}
      else
	{
	hitorstay:
	  if (playertotal <= 21)
	    {
	      cout << "\n 1 Hit \n 2 Stay";
	      int choice;
	      cin >> choice;
	      if (choice == 1 || choice == 2)
		{
		  switch (choice)
		    {
		    case 1:
		      {
			cardcount = cardcount + 1;
			int nextcard = card[cardcount];
			int nextcardnum = nextcard;
			int nextvalue;
			string nextstring;
			valueForCard (nextcardnum, nextvalue, nextstring);
			int nextval = nextvalue;
			string nextstr = nextstring;
			playertotal = playertotal + nextvalue;
			
		if (dealertotal < 17) {
		cardcount = cardcount + 1;
	    int dealercard = card[cardcount];
		int dealercardnum = dealercard;
		int dealervalue;
		string dealerstring;
		valueForCard (dealercardnum, dealervalue, dealerstring);
		int dealerval = dealervalue;
		string dealerstr = dealerstring;
        dealertotal = dealertotal + dealervalue;
                
		cout << " \n Dealer drew a " << dealerstring;
		}else{
		cout << "\n Dealer stayed";

            
            
			cout << "\n You drew a " << nextstr;
		      }
		      }
		    case 2:
		      {
			goto endround;
		      }
		    }
		}else{
		  cout << "Please enter a valid value!";
		  goto hitorstay;
		}
		

	endround:
	
	if (dealertotal < 17){
		while (dealertotal < 17) {
		cardcount = cardcount + 1;
	    int dealercard = card[cardcount];
		int dealercardnum = dealercard;
		int dealervalue;
		string dealerstring;
		valueForCard (dealercardnum, dealervalue, dealerstring);
		int dealerval = dealervalue;
		string dealerstr = dealerstring;
        dealertotal = dealertotal + dealervalue;
                
		cout << "\n Dealer drew a " << dealerstring;
		}
				
		}else{
		cout << "\n  stayed";
			   	}
		}

	    }

	cout << "\n Player Total: " << playertotal << "\n Dealer Total: " << dealertotal;
	  if (playertotal < 22 && (dealertotal > 21 || dealertotal < playertotal))
	    {
	      cout << "\n You win!";
	      cash = cash + wager;
	    }
	  else if (dealertotal < 22 && (playertotal > 21 || playertotal < dealertotal))
	    {
	      cout << "\n You lose!";
	      cash = cash - wager;
	    }
	  else if ((playertotal > 21 && playertotal > 21) || (playertotal = dealertotal))
	    {
	      cout << "\n Tie!";
	    }

    if (cash <= 0)
	{
	  cout << "\n Not enough cash to continue. Play again next time!";
	  return 0;
	}

    endmenu:
      cout << " \n \n 1 Play Again \n 2 Quit Game ";
      int answer;
      cin >> answer;
      if (answer == 1)
	{
	  goto start;
	}
      else if (answer == 2)
	{
	  cout << "\n Thank you for playing!";
	  return 0;
	}
      else
	{
	  cout << "\n Please enter a valid entry.";
	  goto endmenu;
	}

}				//main




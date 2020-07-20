#include <iostream>

using namespace std


class card{
public:	
	enum color {Spade='S', Clubs='C', Heart='H', Diamond='D'};
	enum rank {ace=1,two=2,three=3,four=4,five=5,six=6,seven=7,eight=8,nine=9,ten=10,jack=11,queen=12,king=13};
	
	card(int v, char s){
		_value = v;
		_suit = s;
	}
	
	int get_value(){
		return _value;
	}
	
	string get_suit(){
		return _suit;
	}

private:
	int _value;
	char _suit;
}

class deck{
public:
	deck(){
		for(int i = 0; i<52; i++){
			
		}
	}
	card deal_top_card();
	void shuffle();

private:
	card all_cards[52];

}



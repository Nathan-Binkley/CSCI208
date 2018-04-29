template <class t>
class Monte
{
private:
	t objects[3];
public:
	Monte();
	Monte(string name);
	Monte(int rank, Suit name);
	void shuffle();

	void setOne(t m);
	void setTwo(t m2);
	void setThree(t m3);

	bool pickCard(int o);
	bool pickMarble(int o);

	t pick(int i);

	/*
	string toStringCard();
	string toStringMarble();
	*/
};

template <class t>
t Monte<t>::pick(int i){
	return objects[i];
}

template <class t>
Monte<t>::Monte()
{
		int capacity = 3;
		t temp;
}
template <class t>
Monte<t>::Monte(string name)
{
		int capacity = 3;
		t temp(name);
}
template <class t>
Monte<t>::Monte(int rank, Suit name){
	Card temp;
	temp.setRank(rank);
	temp.setSuit(name);
}
template <class t>
void Monte<t>::shuffle()
{
	int r;
  t temp;
  for(int i = 0; i < 3; i++){
    //cout << "Made it to shuffle for " << i << endl;
    r = (rand() % 3);
    //cout << "Verified r to rand " << endl;
    temp = objects[i];
    objects[i] = objects[r];
    objects[r] = temp;
    //cout << "shuffled " << i << endl;
    //cout<< top << endl;

  }
}

template <class t>
void Monte<t>::setOne(t m)
{
	objects[0] = m;
}

template <class t>
void Monte<t>::setTwo(t m2)
{
	objects[1] = m2;
}

template <class t>
void Monte<t>::setThree(t m3)
{
	objects[2] = m3;
}

template <class t>
bool Monte<t>::pickCard(int o)
{
	int s = objects[o].getRank();
	if(s = 12){
		return true;
	}
	return false;
}
template <class t>
bool Monte<t>::pickMarble(int o)
{
	string s = objects[o].getColor();
	if(s = "blue")
	{
		return true;
	}
	return false;
}
/*
template <class t>
string Monte<t>::toStringCard()
{
	return myRank + " of " + mySuit;

}
template <class t>
string Monte<t>::toStringMarble()
{
	return color + " ";
}cpp
*/

//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 17 Exercise 13

#include "std_lib_facilities_update.h"

struct God {
	God(string n, string m, string v, string w)
		: name{ n }, mythology{ m }, vehicle{ v }, weapon{ w }{}
	string name;
	string mythology;
	string vehicle;
	string weapon;
};

class Link {
public:
	God god;

	Link(const God& g, Link* p = nullptr, Link* s = nullptr)
		: god{ g }, prev{ p }, succ{ s } { }

	Link(const string& n, const string& m, const string& v, const string& w, Link* p = nullptr, Link* s = nullptr)
		: god{ n, m, v, w }, prev{ p }, succ{ s } { }

	Link* insert(Link* n);						// insert n before this object
	Link* add(Link* n);							// insert n after this object
	Link* add_ordered(Link* n);					// insert n at lexicographical position
	Link* erase();								// remove this object from list
	Link* find(const string& s);				// find s in list
	const Link* find(const string& s) const;	// find s in const list

	Link* advance(int n) const;					// move n positions in list

	Link* next() const { return succ; }
	Link* previous() const { return prev; }
private:
	Link* prev;
	Link* succ;
};

Link* Link::insert(Link* n)						// inser n before this; return n
{
	//cout << this->god.name << endl;

	if (n == nullptr) return this;				// nothing to insert
	if (this == nullptr) return n;				// nothing to insert into

	n->succ = this;								// this comes after n
	if (this->prev) this->prev->succ = n;		// if this has a predecessor this's predecessor's successor becomes n
	n->prev = this->prev;						// this's predecessor becomes n's predecessor
	this->prev = n;								// n becomes this's predecessor
	return n;
}

Link* Link::add(Link* n)						// insert n after this; return n
{
	if (n == nullptr) return this;				// nothing to insert
	if (this == nullptr) return n;				// nothing to insert into

	n->prev = this;								// this comes before n
	if (this->succ) this->succ->prev = n;		// if this has a successor this's successor's predecessor becomes n
	n->succ = this->succ;						// this's successor becomes n's successor
	this->succ = n;								// n becomes this's predecessor
	return n;
}

Link* Link::add_ordered(Link* n)
{
	if (n->god.name < this->god.name)			// if new god name is smaller than current god
	{
		this->prev = n;
		n->succ = this;
		return n;
	}
	else
	{
		Link* p = this;
		while (p->succ)
		{
			if (n->god.name > p->god.name && n->god.name < p->succ->god.name)
			{
				p->add(n);
				return this;
			}

			p = p->succ;
		}
		p->add(n);
	}

	return this;
}

Link* Link::erase()								// remove *this from list; return this's sucessor
{
	if (this == nullptr) return nullptr;
	if (this->succ) this->succ->prev = this->prev;
	if (this->prev) this->prev->succ = this->succ;
	this->prev = nullptr;
	this->succ = nullptr;
	return this;
}

Link* Link::find(const string& s)				// find s in list;
{												// return nullptr for "not found"
	Link* p = this;
	while (p)
	{
		if (p->god.name == s) return p;
		p = p->succ;
	}
	return nullptr;
}

const Link* Link::find(const string& s) const
{
	const Link* p = this;
	while (p)
	{
		if (p->god.name == s) return p;
		p = p->succ;
	}
	return nullptr;
}

Link* Link::advance(int n) const				// move n positions in list
{												// return nullptr for "not found"
												// positive n moves forward, negative backward
	const Link* p = this;
	if (p == nullptr) return nullptr;
	if (0 < n) {
		while (n--) {
			if (p->succ == nullptr) return nullptr;
			p = p->succ;
		}
	}
	else if (n < 0) {
		while (n++) {
			if (p->succ == nullptr) return nullptr;
			p = p->succ;
		}
	}
}

void print_all(Link* p)
{	
	while (p) {
		cout << "{";
		cout << p->god.name << ", "
			<< p->god.mythology << ", "
			<< p->god.vehicle << ", "
			<< p->god.weapon;
		cout << "}";
		if (p = p->next()) cout << ",";
		cout << endl;
	}	
}

void full_print_out(Link* p)
{
	while (p) {
		cout << "{";
		if (p->previous())
		{
			cout << p->previous()->god.name << ", ";
		}
		else
		{
			cout << """" << ", ";
		}
		
		cout << p->god.name << ", ";

		if (p->next())
		{
			cout << p->next()->god.name;
		}
		else
		{
			cout << """";
		}

		cout << "}";
		if (p = p->next()) cout << ",";
		cout << endl;
	}
}

void LinkTestOne()
{
	cout << "Link Test 1:" << endl;

	Link* norse_gods = new Link{ "Thor", "", "", "" };
	norse_gods = norse_gods->insert(new Link{ "Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir" });
	norse_gods = norse_gods->insert(new Link{ "Zeus", "Greek", "", "lightning" });
	norse_gods = norse_gods->insert(new Link{ "Freia", "", "", "" });

	Link* sorted_norse_gods = new Link{ "Thor", "", "", "" };
	sorted_norse_gods = sorted_norse_gods->add_ordered(new Link{ "Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir" });
	sorted_norse_gods = sorted_norse_gods->add_ordered(new Link{ "Zeus", "Greek", "", "lightning" });
	sorted_norse_gods = sorted_norse_gods->add_ordered(new Link{ "Freia", "", "", "" });

	cout << "Unsorted: " << endl;
	print_all(norse_gods);
	cout << "Sorted: " << endl;
	print_all(sorted_norse_gods);
	cout << endl;
}

void LinkTestTwo()
{
	cout << "Link Test 2:" << endl;

	Link* gods = new Link{ "Thor", "Norse", "Chariot", "Mjolnir" };
	gods = gods->insert(new Link{ "Odin", "Norse", "Sleipner", "Gungnir" });
	gods = gods->insert(new Link{ "Zeus", "Greek", "", "lightning" });
	gods = gods->insert(new Link{ "Freia", "Norse", "chariot", "Brisingamen" });
	gods = gods->insert(new Link{ "Hera", "Greek", "chariot", "pomegranate" });
	gods = gods->insert(new Link{ "Tyr", "Norse", "chariot", "spear of justice" });
	gods = gods->insert(new Link{ "Athena", "Greek", "chariot", "thunderbolt" });
	gods = gods->insert(new Link{ "Poseidon", "Greek", "the sea", "trident" });
	gods = gods->insert(new Link{ "Ares", "Greek", "chariot", "random spear" });

	vector<string> norse_gods{ "Odin", "Thor", "Freia", "Tyr" };
	vector<string> greek_gods{ "Zeus", "Hera", "Athena", "Poseidon", "Ares" };

	Link* sorted_norse_gods = nullptr;
	Link* sorted_greek_gods = nullptr;

	//print_all(gods);
	//full_print_out(gods);

	for (int i = 0; i < norse_gods.size(); i++)
	{
		Link* p = gods->find(norse_gods[i]);
		p->erase();

		if (sorted_norse_gods)
		{			
			sorted_norse_gods = sorted_norse_gods->add_ordered(p);
		}			
		else
		{
			sorted_norse_gods = p;
		}
	}	

	
	for (int i = 0; i < greek_gods.size(); i++)
	{
		Link* p = gods->find(greek_gods[i]);
		p->erase();

		if (sorted_greek_gods)
		{			
			sorted_greek_gods = sorted_greek_gods->add_ordered(p);
		}
		else
		{
			sorted_greek_gods = p;
		}
	}

	cout << "Sorted norse gods:" << endl;
	print_all(sorted_norse_gods);

	cout << "Sorted greek gods:" << endl;
	print_all(sorted_greek_gods);
	
}

int main()
try
{
	//LinkTestOne();
	LinkTestTwo();

	keep_window_open();
}
catch (exception& e)
{
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	cerr << "Unknown exception\n";
	return 2;
}

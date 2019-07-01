//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 17 Exercise 11

#include "std_lib_facilities_update.h"

class Link {
public:
	string value;
	
	Link(const string& v, Link* p = nullptr, Link* s = nullptr)
		: value{v}, prev{p}, succ{s} {}

	Link* insert(Link* n);						// insert n before this object
	Link* add(Link* n);							// insert n after this object
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

Link* Link::erase()								// remove *this from list; return this's sucessor
{
	if (this == nullptr) return nullptr;
	if (this->succ) this->succ->prev = this->prev;
	if (this->prev) this->prev->succ = this->succ;
	return this->succ;
}

Link* Link::find(const string& s)				// find s in list;
{												// return nullptr for "not found"
	Link* p = this;
	while (p)
	{
		if (p->value == s) return p;
		p = p->succ;
	}
	return nullptr;
}

const Link* Link::find(const string& s) const
{
	const Link* p = this;
	while (p)
	{
		if (p->value == s) return p;
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
	cout << "{";
	while (p) {
		cout << p->value;
		if (p = p->next()) cout << ",";
	}
	cout << "}";
}

int main()
{
	Link* norse_gods = new Link{ "Thor" };
	norse_gods = norse_gods->insert(new Link{ "Odin" });
	norse_gods = norse_gods->insert(new Link{ "Zeus" });
	norse_gods = norse_gods->insert(new Link{ "Freia" });

	Link* greek_gods = new Link{ "Hera" };
	greek_gods = greek_gods->insert(new Link{ "Athena" });
	greek_gods = greek_gods->insert(new Link{ "Mars" });
	greek_gods = greek_gods->insert(new Link{ "Poseidon" });

	Link* p = greek_gods->find("Mars");
	if (p) p->value = "Ares";

	Link* pp = norse_gods->find("Zeus");
	if (pp) {
		if (pp == norse_gods) norse_gods = pp->next();
		pp->erase();
		greek_gods = greek_gods->insert(pp);
	}

	print_all(norse_gods);
	cout << endl;

	print_all(greek_gods);
	cout << endl;

	keep_window_open();
}

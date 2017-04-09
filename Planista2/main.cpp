#include <stdio.h>
//#include <iostream>

struct list
{
	list * next;
	int data;

};
struct processor
{
	list * p1;
	list * p2;
	list * p3;

	processor(); // konstruktor
	~processor(); // destruktor
	list * top(int priority);
	void push(int v, int priority);
	void pop(int priority);
	void show(int priority);
	list * search_element(int elem, int priority);
	void proc_manager();
	int list_size(int priority);
	void remove_task(int task);
	void remove_element(list * element, int priority);
	void change_priority(int task, int priority);
};
//---------------------
// Metody obiektu processor
//---------------------
// Konstruktor
//------------
processor::processor()
{
	p1 = NULL;
	p2 = NULL;
	p3 = NULL;

}
// Destruktor - zwalnia tablicê dynamiczn¹
//----------------------------------------
processor::~processor()
{
	while (p1) pop(1);
	while (p2) pop(0);
	while (p3) pop(-1);

}
// Wyciaga heada
//----------------------------------------
list * processor::top(int priority)
{
	if (priority == 1)
		if (p1) return p1;
	if (priority == 0)
		if (p2) return p2;
	if (priority == -1)
		if (p3) return p3;	

	return NULL;
}

// Zapisuje na stos
//-----------------
void processor::push(int v, int priority)
{
	list * e = new list;
	list * q = new list();
	e->data = v;
	q->data = v;

	if (priority == 1)
	{
		if (p1 != NULL)
		{
			e = p1;
			while (e->next != p1)
			{
				e = e->next;
			}
			e->next = q;
			q->next = p1;
		}
		else
		{
			e->next = e;
			p1 = e;
		}
	}
	if (priority == 0)
	{
		if (p2 != NULL)
		{
			e = p2;
			while (e->next != p2)
			{
				e = e->next;
			}
			e->next = q;
			q->next = p2;
		}
		else
		{
			e->next = e;
			p2 = e;
		}
	}
	if (priority == -1)
	{
		if (p3 != NULL)
		{
			e = p3;
			while (e->next != p3)
			{
				e = e->next;
			}
			e->next = q;
			q->next = p3;
		}
		else
		{
			e->next = e;
			p3 = e;
		}
	}
}
// Usuwa ze stosu
//---------------
void processor::pop(int priority)
{
	if (priority == 1)
	{
		if (p1)
		{
			list * e = p1->next;
			p1->next = e->next;
			if (e->next == e) p1 = NULL;
			delete e;
		}
	}
	if (priority == 0)
	{
		if (p2)
		{
			list * e = p2->next;
			p2->next = e->next;
			if (e->next == e) p2 = NULL;
			delete e;
		}
	}
	if (priority == -1)
	{
		if (p3)
		{
			list * e = p3->next;
			p3->next = e->next;
			if (e->next == e) p3 = NULL;
			delete e;
		}
	}
}

// Usuwa wybrany element
//---------------
void processor::remove_element(list * element, int priority)
{
	list * l1 = element;
	list * l2 = element->next;
	list * l3 = l2->next;

	if (priority == 1)
	{
		if (l2 == p1)
		{
			if (l2->next == p1)
			{
				p1 = NULL;
			}
			else
			{
				p1 = p1->next;
				l1->next = p1;
				delete l2;
			}
			
		}
		else
		{
			l1->next = l2->next;
			l2->next = NULL;
			delete l2;
		}
		
	}
	if (priority == 0)
	{
		if (l2 == p2)
		{
			if (l2->next == p2)
			{
				p2 = NULL;
			}
			else
			{
				p2 = p2->next;
				l1->next = p2;
				delete l2;
			}

		}
		else
		{
			l1->next = l2->next;
			l2->next = NULL;
			delete l2;
		}

	}
	if (priority == -1)
	{
		if (l2 == p3)
		{
			if (l2->next == p3)
			{
				p3 = NULL;
			}
			else
			{
				p3 = p3->next;
				l1->next = p3;
				delete l2;
			}

		}
		else
		{
			l1->next = l2->next;
			l2->next = NULL;
			delete l2;
		}

	}	
}
// Wyœwietla stos
//---------------
void processor::show(int priority)
{
	list * l;

	l = top(priority);

	if (l)
		do
		{
			if (l->next != NULL)
				printf("%d ", l->data);
			else
			{
				printf("%d", l->data);
				break;
			}
			l = l->next;
		} while (l != top(priority));
}

// Szuka element o okreslonym priorytecie
//---------------
list * processor::search_element(int elem, int priority)
{
	list * S;
	list * target;
	
	if(priority == 1)
		S = p1;
	if (priority == 0)
		S = p2;
	if (priority == -1)
		S = p3;

	target = S;
	bool searched = false;
	if (S != NULL)
	{
		do
		{
			if (target->next->data == elem)
			{
				searched = true;
				break;
			}
			target = target->next;

		} while (target != S);
		if (searched)
			return target;

	}
	return NULL;
}

// Oblicza liczbe elementow listy
//---------------
int processor::list_size(int priority)
{
	int c = 0;
	list * p = top(priority);

	if (p)
		do
		{
			c++;
			p = p->next;
		} while (p != top(priority));
		return c;
}

// Porusza sie po listach - polecenie 'n'
//---------------
void processor::proc_manager()
{
	if (p1 != NULL)
	{
		printf("%d\n", p1->data);
		p1 = p1->next;
	}
	else
	{
		if (p2 != NULL)
		{
			printf("%d\n", p2->data);
			p2 = p2->next;
		}
		else
		{
			if (p3 != NULL)
			{
				printf("%d\n", p3->data);
				p3 = p3->next;
			}
			else
			{
				printf("idle");
				printf("\n");
			}
		}

	}
}

void processor::remove_task(int task)
{

	list * tmp1 = search_element(task, 1);
	list * tmp2 = search_element(task, 0);
	list * tmp3 = search_element(task, -1);

	if (tmp1 != NULL)
	{
		if (tmp1->next->data == task)
		{
			remove_element(tmp1, 1);
		}
			
	}
	if (tmp2 != NULL)
	{
		if (tmp2->next->data == task)
		{
			remove_element(tmp2, 0);
		}
			
	}
	if (tmp3 != NULL)
	{
		if (tmp3->next->data == task)
		{
			remove_element(tmp3, -1);
		}
			
	}
	
	
}
void processor::change_priority(int task, int priority)
{
	remove_task(task);
	push(task, priority);
}
int main()
{
	processor * manager = new processor();

	const int rozmiar = 20;

	char t[rozmiar] = { '\0' };
	char *p, *q;

	bool endOfNumber = false;
	bool isNumber = false;
	bool canSetPriority = false;
	bool removeTask = false;
	bool canSetProcess = false;
	bool canChangePriority = false;
	bool canRemove = false;
	bool canMoveProcess = false;
	bool canMove = false;

	int task = 0;
	int liczba = 0;
	int calaLiczba = 0;
	int liczbaDoUsuniecia = 0;
	int liczbaDoMovniecia = 0;

	while (fgets(t, sizeof t, stdin))
	{
		liczba = 0;
		endOfNumber = false;
		isNumber = false;
		calaLiczba = 0;
		canSetPriority = false;
		canChangePriority = false;
		canSetProcess = false;
		removeTask = false;
		canRemove = false;
		canMoveProcess = false;
		liczbaDoUsuniecia = 0;
		canMove = false;
		bool space = false;

		for (p = t, q = t + sizeof t; p < q; p++)
		{
			switch (*p)
			{
			case '\n':
				endOfNumber = true;
				break;
			case ' ':
				space = true;
				endOfNumber = true;
				break;
			case 'c':
				canSetProcess = true;
				break;
			case 'p':
				canChangePriority = true;
				break;
			case 'n':
				manager->proc_manager();
				break;
			case 't':
				removeTask = true;
				break;
			case 'l':
				printf("1: ");
				manager->show(1);
				printf("\n");
				printf("0: ");
				manager->show(0);
				printf("\n");
				printf("-1: ");
				manager->show(-1);
				printf("\n");
				break;
			}
			if (*p >= 48 && *p <= 57 || *p == '-')
			{
				space = false;
				endOfNumber = false;
				if (canSetPriority && canSetProcess)
				{
					switch (*p)
					{

					case '0':
						manager->push(calaLiczba, 0);
						break;
					case '1':
						manager->push(calaLiczba, 1);
						break;
					default:
						manager->push(calaLiczba, -1);
						break;
					}
					canSetPriority = false;
					calaLiczba = 0;
					liczba = 0;
					break;
				}
				if (*p != '-')
				{
					liczba = *p - 48;
					calaLiczba = calaLiczba * 10 + liczba;
					isNumber = true;
				}
			}

			if (endOfNumber && isNumber)
			{
				canSetPriority = true;
				endOfNumber = false;
				isNumber = false;
				canRemove = true;
				canMoveProcess = true;
				liczbaDoUsuniecia = calaLiczba;
				liczbaDoMovniecia = calaLiczba;
			}
			
			if (removeTask && canRemove)
			{
				manager->remove_task(liczbaDoUsuniecia);
			}
			if (canChangePriority && canSetPriority && canMoveProcess)
			{
				task = liczbaDoMovniecia;
				canMoveProcess = false;
			}
			if (canSetPriority && canChangePriority && !space)
			{
				if (*p == '-')
				{
					manager->change_priority(task, -1);
				}
				else
				{
					int priority = *p - 48;
					manager->change_priority(task, priority);
				}
				break;
			}
		}
		for (int i = 0; i < rozmiar; i++)
			t[i] = '\0';
	}
	return 0;
}
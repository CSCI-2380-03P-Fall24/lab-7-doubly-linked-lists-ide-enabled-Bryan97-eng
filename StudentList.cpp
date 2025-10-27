	#include "StudentList.h"

	// Define a constructor to initialize the list. The list starts with no Students
    StudentList::StudentList() {

		head = nullptr;
		tail = nullptr; 
		numStudents = 0; 


	}

	// return the number of students currently in the list
	int StudentList::listSize() {
		
		if(head == nullptr){
			cout << "empty list" << endl; 
			return 0; 
		} else {
			int counter = 0;
			Node* temp = head;
			while(temp != nullptr){
				temp = temp->next;
				counter++; 
				
			}
			return counter; 
		}
		
	}

	//add a Node with a student to the front (head) of the list.
	void StudentList::addFront(Student s) {
		Node* newStudent = new Node(s);
		
		if(head == nullptr){
			head = tail = newStudent;

		} else {
			newStudent->next = head;
			head->prev = newStudent;
			head = newStudent;

		}
		numStudents++;

	}

	//add a Node with a student to the back (tail) of the list.
	void StudentList::addBack(Student s) {
		Node* newStudent = new Node(s);
		
		if(head == nullptr){
			head = tail = newStudent;

		} else {
			tail->next = newStudent;
			newStudent->prev = tail;
			tail = newStudent;

		}
		numStudents++;
	

	}

	//Print out the names of each student in the list.
	void StudentList::printList() {
		
		if(head == nullptr){
			cout << "empty list" << endl; 
			return; 
		} 
			Node* temp = head;
			while (temp != nullptr){
				cout << temp->data.name << endl; 
				temp = temp->next;
				
			}


	}

	// Remove the Node with the student at the back (tail) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popBack() {
		if(head == nullptr){
			cout << "cannot pop" << endl;
			return;
		}
		if(head == tail){
			delete head;
			head = nullptr;
			tail = nullptr;
			return;

		}

		Node* temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete temp; 


	}

	// Remove the Node with the student at the front (head) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popFront() {
		if(head == nullptr){
			cout << "cannot pop";
			return;
		}
		if(head == tail){
			 delete head;
        	head = nullptr;
        	tail = nullptr;
        	return;
		}

		 Node* temp = head;
		 head = head->next;
		 head->prev = nullptr;
		 delete temp;

	}

	//insert a student at the position "index".
	// for this list, count head as index 0
	// if index is outside of current list range, 
	// print a message and insert the student at the back of the list
	// the previous Node at your target index should be moved forward. "For exampe, Node with student at index i, becomes index i+1" 
	// Remember that you already have methods that can add students to the front or back of list if needed! Don't repeat this code.
	void StudentList::insertStudent(Student s, int index) {

		if(head == nullptr){

			cout << "Empty list\n";
			addBack(s);
			
		} else if (index <= 0) {

        addFront(s);

   		} else if (index >= numStudents) {

        cout << "Outside of list range!\n";
        addBack(s);

  		  } else {

        Node* newStudent = new Node(s);
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        newStudent->next = temp;
        newStudent->prev = temp->prev;
		if(temp->prev != nullptr){
			 temp->prev->next = newStudent;
		}
       
        temp->prev = newStudent;
		if(temp == head){
			head = newStudent;
		}

        numStudents++;
    }

	}

	//find the student with the given id number and return them
	// if no student matches, print a message 
	// and create and return a dummy student object
	Student StudentList::retrieveStudent(int idNum) {
		Node* temp = head; 
		while(temp != nullptr){
			
			if( temp->data.id == idNum){
				return temp->data; 
			}

			temp = temp->next; 
		}
		Student dumby;

		
		return dumby;
	}

	// Remove a Node with a student from the list with a given id number
	// If no student matches, print a message and do nothing
	void StudentList::removeStudentById(int idNum) {

		Node* temp = head; 
		while(temp != nullptr){
			
			if( temp->data.id == idNum){
					// remove student node here 

				// return after to stop the list 
			}

			temp = temp->next; 
		}

		cout << "No student found\n";


	}

	//Change the gpa of the student with given id number to newGPA
	void StudentList::updateGPA(int idNum, float newGPA) {}

	//Add all students from otherList to this list.
	//otherlist should be empty after this operation.
	/*
	For example, if the list has 3 students:
	s1 <-> s2 <-> s3
	and otherList has 2 students
	s4 <-> s5
	then after mergeList the currently list should have all 5 students
	s1 <-> s2 <-> s3 <-> s4 <-> s5
	and otherList should be empty and have zero students.
	*/
	void StudentList::mergeList(StudentList &otherList) {}

	//create a StudentList of students whose gpa is at least minGPA.
	//Return this list.  The original (current) list should
	//not be modified (do not remove the students from the original list).
	StudentList StudentList::honorRoll(float minGPA) {
		StudentList fixthis;
		return fixthis;
	}

	//remove all students whose GPA is below a given threshold.
	// For example, if threshold = 3.0, all students with GPA less than 3.0
	// should be removed from the list. 
	// Be sure to correctly update both head and tail pointers when removing 
	// from the front or back, and adjust numStudents accordingly.
	// If the list is empty, print a message and do nothing.
	void StudentList::removeBelowGPA(float threshold) {}

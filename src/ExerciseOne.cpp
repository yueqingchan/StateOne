//
// Created by 87572 on 19/4/17.
//

#include "../include/ExerciseOne.h"

struct Person {
    int age;
    char *name;
};

Person **allocateMemory(int num);

void show_info(Person **pPerson, int num);

void free_memory(Person **pPerson,int num);

/**
 * K1:===========================================================
 */
void exercise_one_test_struct() {

    int num = 10;
    Person **pPerson = allocateMemory(num);
    show_info(pPerson, num);
    free_memory(pPerson,num);


}

Person **allocateMemory(int num) {

    Person **pPerson = (Person **) malloc(sizeof(struct Person *) * num);
    for (int i = 0; i < num; ++i) {
        pPerson[i] = static_cast<Person *>(malloc(sizeof(struct Person)));
        pPerson[i]->name = static_cast<char *>(malloc(100 * sizeof(char)));
        pPerson[i]->age = i;
        sprintf(pPerson[i]->name, "NAME is %d", i);
    }
    return pPerson;

};

void show_info(Person **pPerson, int num) {
    for (int i = 0; i < num; ++i) {

        cout << "NAME: " << i << " :" << pPerson[i]->name << "AGE: " << pPerson[i]->age << endl;

    }

};

void free_memory(Person **pPerson, int num) {

    if (pPerson == NULL) {
        return;
    }

    for (int i = 0; i < num; ++i) {

        if (NULL == pPerson[i]) {
            return;
        }
        //首先释放最底层的name
        if (NULL != pPerson[i]->name) {
            free(pPerson[i]->name);
            pPerson[i]->name=NULL;
            cout<<"free name"<<i<<endl;
        }
        //释放pPerson*
        free(pPerson[i]);
        pPerson[i] = NULL;
        cout<<"free person"<<i<<endl;

    }

    free(pPerson);

};


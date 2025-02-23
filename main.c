#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} list;

// Fonction pour ins�rer un n�ud � la fin de la liste
list *insert_at_end(list *head, int value) {
    list *new_node = (list *)malloc(sizeof(list));
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    list *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    //Fonction pour supprimer un �l�ment de la liste
    return head;
}

// Fonction pour supprimer un �l�ment de la liste
list *delete_element(list *head, int value) {
    if (head == NULL) {
        return NULL; // Liste vide
    }

    // Si l'�l�ment � supprimer est la t�te
    if (head->data == value) {
        list *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    list *current = head;
    // Parcourir la liste pour trouver l'�l�ment � supprimer
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    // Si l'�l�ment n'est pas trouv�
    if (current->next == NULL) {
        printf("�l�ment %d non trouv� dans la liste.\n", value);
        return head;
    }

    // Supprimer l'�l�ment
    list *temp = current->next;
    current->next = current->next->next;
    free(temp);

    return head;
}

// Fonction pour cr�er la liste
list *create_list() {
    list *head = NULL;
    int value;

    printf("Entrez -1 pour terminer \n");
    printf("Entrez les donn�es : \n");
    scanf("%d", &value);

    while (value != -1) {
        head = insert_at_end(head, value);
        printf("Entrez les donn�es : \n");
        scanf("%d", &value);
    }
    return head;
}

// Fonction pour afficher la liste
void display_list(list *head) {
    list *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    list *my_list = NULL;
    my_list = create_list();
    display_list(my_list);

    int value_to_delete;
    printf("Entrez l'�l�ment � supprimer : ");
    scanf("%d", &value_to_delete);
    my_list = delete_element(my_list, value_to_delete); // Suppression de l'�l�ment
    display_list(my_list);

    // Lib�ration de la m�moire
    list *temp;
    while (my_list != NULL) {
        temp = my_list;
        my_list = my_list->next;
        free(temp);
    }

    return 0;
}

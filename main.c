#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} list;

// Fonction pour insérer un nœud à la fin de la liste
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
    return head;
}

// Fonction pour supprimer un élément de la liste
list *delete_element(list *head, int value) {
    if (head == NULL) {
        return NULL; // Liste vide
    }

    // Si l'élément à supprimer est la tête
    if (head->data == value) {
        list *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    list *current = head;
    // Parcourir la liste pour trouver l'élément à supprimer
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    // Si l'élément n'est pas trouvé
    if (current->next == NULL) {
        printf("Élément %d non trouvé dans la liste.\n", value);
        return head;
    }

    // Supprimer l'élément
    list *temp = current->next;
    current->next = current->next->next;
    free(temp);

    return head;
}

// Fonction pour créer la liste
list *create_list() {
    list *head = NULL;
    int value;

    printf("Entrez -1 pour terminer \n");
    printf("Entrez les données : \n");
    scanf("%d", &value);

    while (value != -1) {
        head = insert_at_end(head, value);
        printf("Entrez les données : \n");
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
    printf("Entrez l'élément à supprimer : ");
    scanf("%d", &value_to_delete);
    my_list = delete_element(my_list, value_to_delete); // Suppression de l'élément
    display_list(my_list);

    // Libération de la mémoire
    list *temp;
    while (my_list != NULL) {
        temp = my_list;
        my_list = my_list->next;
        free(temp);
    }

    return 0;
}

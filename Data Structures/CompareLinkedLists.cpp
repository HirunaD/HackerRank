bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* current1 = head1;
    SinglyLinkedListNode* current2 = head2;

    // Traverse both lists
    while (current1 != nullptr && current2 != nullptr) {
        // Compare the data of the nodes
        if (current1->data != current2->data) {
            return false;
        }
        // Move to the next node
        current1 = current1->next;
        current2 = current2->next;
    }

    // If one list is longer than the other
    if (current1 != nullptr || current2 != nullptr) {
        return false;
    }

    return true;
}
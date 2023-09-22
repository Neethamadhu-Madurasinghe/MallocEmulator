 node_t *head = NULL;
    count(head);
    head = insertBegin(head, 10);
    head = insertBegin(head, 20);
    head = insertBegin(head, 30);
    
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);

    head = insertAfter(head, 30, 35);
    head = insertBefore(head, 50, 45);

    head = insertBefore(head, 60, 55);

    count(head);
    display(head);

    head = deleteBegin(head);
    head = deleteBegin(head);

    display(head);  

    head = deleteEnd(head);
    head = deleteEnd(head);

    display(head);
    count(head);
    head = insertEnd(head, 50);
    head = insertEnd(head, 75);
    display(head);
   // head = deleteAfter(head, 20);
    head = deleteEntireList(head);
    
    display(head);
    head = insertBegin(head, 55);
    // head = insertBefore(head, 100, 55);
    // head = insertBefore(head, 200, 55);
    // head = insertBefore(head, 300, 55);
    // head = insertBefore(head, 400, 55);
    // head = insertBefore(head, 500, 55);
    display(head);
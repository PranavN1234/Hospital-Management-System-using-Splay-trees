# Hospital-Management-System-using-Splay-trees


Abstract
    Splay trees are self branching binary search tree which has the property of re-accessing
  the elements quickly that which are recently accessed. Splay trees have basic operations
  such as Insertion, Search, Deletion. The performance of the splay trees far more efficient
  than other search trees. Splay trees are used in cases where more frequently accessed
  elements should be easier to access than the other elements.


Algorithm Used

    1 Splay function (This function is used to bring а
    Particular element with key ‘k’ to the root position and adjust the tree)
    1.1) We create а right rotate function which rotates an element to the right
    1.2) We create а left rotate function which rotates and element to the left
    1.3) If the element is already in the root position we return it as it is
    1.4) If the element is lesser than the root we move to the left sub tree so we
    perform Right rotation operations, if it’s greater we perform left
    operations
    1.5) If the element is а child element we perform the Zig or Zag operation
    once which involves one rotation
    1.6) If the element is а grandchild or beyond we perform Zig-Zag , Zag-Zag
    or Zig-Zig steps until the element is brought to the root
    1.7) We return the root node which is now the splayed element
    2 Search operation
    2.1) Enter element to search
    2.2) Call the search function passing the element and the root value of the
    tree
    2.3) We perform the splay function as mentioned in step one on the tree
    and splay the searched element to the root position
    2.4) We return the element to be searched in the root position as required
    3 Insert operation
    3.1) Input all the patient details from the user
    3.2) We pass the patient details and the root to the insert function
    3.3) We allocate the node space here and assign the node values to а
    declared node
    3.4) If there is no root present we allocate the node to the root
    3.5) Otherwise we perform splay operation on the key
    3.6) If the element is already present it is moved to the root position
    3.7) Else, we allocate memory and compare it with the root->key
    3.7)1. If k is smaller than the root’s key we make the root as
    the right child of the new node, make left child of the
    root as left child of the new node and make left child
    of the root as null
    3.7)2. If k is larger than the root’s key we make the root as
    the left child of the new node, make right child of the
    root as right child of the new node and make right
    child of the root as null
    3.8) We return the new node of the tree
    4 Delete operation
    4.1) We pass the element to be deleted and the root to the delete function
    of the splay tree
    4.2) If the root is null we return the root as it is
    4.3) Else, we splay the given key to the root position if the key is present it
    goes to the root position or else the last accessed key is moved to the
    root position
    4.4) If new root’s key is not same as key , we return the root and mention
    that the root is not present
    4.5) Else, if the key is present
    4.5)1. If the root does not have а left child we simply deallocate the root and make the right element as the
    new root
    4.5)2. Else, we splay the left hand side of the tree in such а
    way that the tree has no right child tree and the max
    element in the left sub tree is splayed to the root
    position
    4.5)3. We then make the right child of the previous root the
    right child of the new root
    4.5)4. We free the space allocated for the deleted node and
    return the root
    5 Most recently searched element
    5.1) We return the element in the current root position as it is the most
    recently searched element
    6 Driver function
    6.1) We declare а class element of the splay tree
    6.2) We display the Menu to the user and ask him of the choice required to
    make
    6.3) If the option is 1, we input the patient details from the user and pass it
    onto the insert function of the class
    6.4) If the option is 2, we ask the user to input the patient number to be
    deleted and pass the element to the delete function
    6.5) If the option is 3, we ask the user to input the patient number to search
    for and pass it onto the search function
    6.6) If the option is 4, we display the element currently stored in the root
    position to return the most recently accessed element
    6.7) If the option is 5, we display all elements currently present in the
    database
    6.8) If the option is none of the above we display and error
 
 Applications
     • It is used to implement caches. Cache keeps track of the contents of memory locations
    that were recently requested by processor. It can be made to deliver requests much faster
    than main memory. Similarly, splay trees uses this concept of accessing the elements
    quickly that which were recently accessed. Splay trees are used to implement Cache
    algorithms.
    • it has the ability of not to store any data, which results in minimization of memory
    requirements.
    It can also be used for data compression, e.g. dynamic Huffman coding.
    The main ideology behind selecting the splay tree is to reduce the consumption of time
    while re-accessing of the elements and to improve the performance and also to reduce the
    storage space.

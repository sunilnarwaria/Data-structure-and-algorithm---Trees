
int KSmallestUsingMorris(Node *root, int k)
{
  
    int count = 0;
 
    int ksmall = INT_MIN; // store the Kth smallest
    Node *curr = root; // to store the current node
 
    while (curr != NULL)
    {
       
        if (curr->left == NULL)
        {
            count++;
 
            // if count is equal to K then we found the
            // kth smallest, so store it in ksmall
            if (count==k)
                ksmall = curr->key;
 
            // go to current's right child
            curr = curr->right;
        }
        else
        {
            // we create links to Inorder Successor and
            // count using these links
            Node *pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
                pre = pre->right;
 
            // building links
            if (pre->right==NULL)
            {
                //link made to Inorder Successor
                pre->right = curr;
                curr = curr->left;
            }
 
            // While breaking the links in so made temporary
            // threaded tree we will check for the K smallest
            // condition
            else
            {
                // Revert the changes made in if part (break link
                // from the Inorder Successor)
                pre->right = NULL;
 
                count++;
 
                // If count is equal to K then we found
                // the kth smallest and so store it in ksmall
                if (count==k)
                    ksmall = curr->key;
 
                curr = curr->right;
            }
        }
    }
    return ksmall; //return the found value
}

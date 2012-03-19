/*
 * Non-recursive tree traversal algorithms
 */

#define maxsize 100
typedef struct
{
    Bitree Elem[maxsize];
    int top;
}SqStack;

/* Pre order travseral */
void PreOrderUnrec(Bitree t)
{
    SqStack s;
    StackInit(s);
    p=t;
    
    while (p!=null || !StackEmpty(s))
    {
        while (p!=null)             //����������
        {
            visite(p->data);
            push(s,p);
            p=p->lchild;       
        }//end while
        
        if (!StackEmpty(s))         //ͨ����һ��ѭ���е���Ƕwhileʵ������������
        {
            p=pop(s);
            p=p->rchild;        
        }//end if
                
    }//end while 
    
}//PreOrderUnrec

/* In order traversal */
void InOrderUnrec(Bitree t)
{
    SqStack s;
    StackInit(s);
    p=t;
    while (p!=null || !StackEmpty(s))
    {
        while (p!=null)             //����������
        {
            push(s,p);
            p=p->lchild;
        }//endwhile
        
        if (!StackEmpty(s))
        {
            p=pop(s);
            visite(p->data);        //���ʸ����
            p=p->rchild;            //ͨ����һ��ѭ��ʵ������������
        }//endif   
    
    }//endwhile

}//InOrderUnrec


typedef enum{L,R} tagtype;
typedef struct 
{
    Bitree ptr;
    tagtype tag;
}stacknode;

typedef struct
{
    stacknode Elem[maxsize];
    int top;
}SqStack;

/* Post order traversal */
void PostOrderUnrec(Bitree t)
{
    SqStack s;
    stacknode x;
    StackInit(s);
    p=t;
    
    do 
    {
        while (p!=null)        //����������
        {
            x.ptr = p; 
            x.tag = L;         //���Ϊ������
            push(s,x);
            p=p->lchild;
        }
    
        while (!StackEmpty(s) && s.Elem[s.top].tag==R)  
        {
            x = pop(s);
            p = x.ptr;
            visite(p->data);   //tagΪR����ʾ������������ϣ��ʷ��ʸ����       
        }
        
        if (!StackEmpty(s))
        {
            s.Elem[s.top].tag =R;     //����������
            p=s.Elem[s.top].ptr->rchild;        
        }    
    }while (!StackEmpty(s));
}//PostOrderUnrec 
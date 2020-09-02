#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
int num=1;

int init_node(struct node *nd)
{
  nd->type = e_null_node;
  nd->val.str = NULL;
  nd->son = NULL;
  nd->parent = NULL;
  nd->next = NULL;

  return RET_SUCCESS;
}

// AST抽象语法树初始化
void init_ast()
{
  init_node(&root);
}


int add_son_node(struct node *parent, struct node *son)
{
    if(NULL!=parent && NULL!=son)
    {
        if(parent->son==NULL)
        {
            parent->son=son;
			son->parent = parent;// KTX
        }
        else
        {
            struct node *tmp_node=parent->son;

            while(NULL!=tmp_node->next)
            {
                tmp_node=tmp_node->next;
            }

            tmp_node->next=son;
            son->parent=parent;

        }
        return ADD_SON_NODE_SUCCESS;
    }
    else
    {
        return NULL_NODE_POINTER;
    }

    return ADD_SON_NODE_SUCCESS;
}


int add_brother_node(struct node *last, struct node *new_brother)
{
    if(NULL!=last && NULL!=new_brother)
    {
        struct node *tmpparent=NULL;

        last->next=new_brother;
        new_brother->parent= last->parent;

        return ADD_BROTHER_NODE_SUCCESS;
    }
    else
    {
        return NULL_NODE_POINTER;
    }
}

int set_node_val_str(struct node *nd, char *str)
{
    if(NULL==nd || NULL==str)
        return NULL_NODE_POINTER;
    else
    {
        if(NULL!=nd->val.str)
            free(nd->val.str);
        nd->val.str=(char *)malloc(strlen(str)+1);
        strcpy(nd->val.str,str);

        return SET_NODE_VAL_STR_SUCCESS;
    }

    return SET_NODE_VAL_STR_SUCCESS;
}

int new_node(struct node **result)
{
    if(NULL!=result)
    {
        *result=(struct node *)malloc(sizeof(struct node));
        if(init_node(*result)==INIT_NODE_SUCCESS)
            return NEW_NODE_SUCCESS;
        else
            return MEMORY_ALLOC_ERROR;
    }
    else
    {
        return NULL_NODE_POINTER;
    }

    return NEW_NODE_SUCCESS;
}


struct node* get_last_node(struct node *N)
{
	struct node *tmp = N;
	if (N == NULL) {
		return NULL;
	}
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	return tmp;
}

void write_file(struct node *root)
{
    root->val.num=num++;

    FILE   *   fp;
    fp=fopen("graph.dot","w+");
    char* str="digraph pic{\n";
    fputs(str,fp);
    fputs("\t",fp);
    fprintf(fp,"%d",root->val.num);
    fputs("[label=\"",fp);
    fputs(root->val.str,fp);
    fputs("\"];\n",fp);
    fclose(fp);

    SearchTree(root);

    fp=fopen("graph.dot","a+");
    fputs("}",fp);
    fclose(fp);
}


void SearchTree(struct node *root)
{
    FILE   *   fp;
    fp=fopen("graph.dot","a+");

	int i = 0;
	struct node *son = root->son;

    while (son != NULL)
    {
        son->val.num=num++;
        fputs("\t",fp);
        fprintf(fp,"%d",son->val.num);
        fputs("[label=\"",fp);
        fputs(son->val.str,fp);
        fputs("\"];\n",fp);
        fputs("\t",fp);
        fprintf(fp,"%d",root->val.num);
        fputs("->",fp);
        fprintf(fp,"%d",son->val.num);
        fputs(";\n",fp);
        fclose(fp);
        SearchTree(son);
        son = son->next;

	}
}


void OutputAST(void)
{
    write_file(&root);
    char *path = NULL;
    path = getcwd(NULL,0);
    int flag;
/*
    char *ss = (char*)malloc(sizeof(path)*2+30);
    sprintf(ss, "dot -Tpng %s\\graph.dot -o %s\\graph.png", path, path);
    system(ss);

    sprintf(ss,"%s\\graph.png",path);
    puts(ss);*/
}

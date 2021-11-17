/*
在表头 表尾 位置插入新节点
*/

#include<stdio.h>
#include<stdlib.h>

struct Node //创建一个Node结构体
{
	int data;//数据域
	struct Node* next;//指针域
};
struct Node* head = NULL;//空表嗯

void InsertListBegin( int newdata ) //插入表头
{
	struct Node* InsertNode = (struct Node*)malloc(sizeof(struct Node*));
	// 根据该指针 所需字节数 分配内存空间给 InsertNode
	if (InsertNode == NULL)
	{
		printf("内存分配失败");
		exit(0);//推出程序
	}
	else {
		InsertNode->data = newdata; //填充新节点的数据域
		InsertNode->next = NULL; //填充新节点的指针域，同时作为表尾
		head = InsertNode; // 表头更新 指向新插入的节点
		printf("表头已经插入新节点\n");
	}
}

void InsertListLast( int newdata )//插入表尾
{
	struct Node* InsertNode = (struct Node*)malloc(sizeof(struct Node*));
	if (InsertNode == NULL) //分配失败
	{
		printf("新节点内存分配失败\n");
		exit(0); //正常退出
	}
	else // 分配成功
	{
		if ( head == NULL )//插入到空表
		{
			head = InsertNode; //更新表头
			InsertNode->data = newdata;
			InsertNode->next = NULL;
			printf("成功插入新节点到表尾 (空表)\n");
		}
		else //非空表
		{
			//先遍历
			struct Node* TempNode = head;//临时节点
			while (TempNode->next != NULL)
			{
				TempNode = TempNode->next; // 刷新指针 不断往前遍历
			} 
			//当指向表尾时 TempNode 仍停留在表尾节点的地址中，没有刷新为NULL
			//遍历完成 TempNode 指向表尾
			InsertNode->data = newdata;
			InsertNode->next = NULL;
			TempNode->next = InsertNode;
			printf("成功插入新节点到表尾(非空表)\n");

		}
	}
}	

int main(void)
{
	int newdata;

	scanf_s("%d", &newdata);
	InsertListBegin(newdata);
	InsertListLast(newdata);

	return 0;
}
/*
�ڱ�ͷ ��β λ�ò����½ڵ�
*/

#include<stdio.h>
#include<stdlib.h>

struct Node //����һ��Node�ṹ��
{
	int data;//������
	struct Node* next;//ָ����
};
struct Node* head = NULL;//�ձ���

void InsertListBegin( int newdata ) //�����ͷ
{
	struct Node* InsertNode = (struct Node*)malloc(sizeof(struct Node*));
	// ���ݸ�ָ�� �����ֽ��� �����ڴ�ռ�� InsertNode
	if (InsertNode == NULL)
	{
		printf("�ڴ����ʧ��");
		exit(0);//�Ƴ�����
	}
	else {
		InsertNode->data = newdata; //����½ڵ��������
		InsertNode->next = NULL; //����½ڵ��ָ����ͬʱ��Ϊ��β
		head = InsertNode; // ��ͷ���� ָ���²���Ľڵ�
		printf("��ͷ�Ѿ������½ڵ�\n");
	}
}

void InsertListLast( int newdata )//�����β
{
	struct Node* InsertNode = (struct Node*)malloc(sizeof(struct Node*));
	if (InsertNode == NULL) //����ʧ��
	{
		printf("�½ڵ��ڴ����ʧ��\n");
		exit(0); //�����˳�
	}
	else // ����ɹ�
	{
		if ( head == NULL )//���뵽�ձ�
		{
			head = InsertNode; //���±�ͷ
			InsertNode->data = newdata;
			InsertNode->next = NULL;
			printf("�ɹ������½ڵ㵽��β (�ձ�)\n");
		}
		else //�ǿձ�
		{
			//�ȱ���
			struct Node* TempNode = head;//��ʱ�ڵ�
			while (TempNode->next != NULL)
			{
				TempNode = TempNode->next; // ˢ��ָ�� ������ǰ����
			} 
			//��ָ���βʱ TempNode ��ͣ���ڱ�β�ڵ�ĵ�ַ�У�û��ˢ��ΪNULL
			//������� TempNode ָ���β
			InsertNode->data = newdata;
			InsertNode->next = NULL;
			TempNode->next = InsertNode;
			printf("�ɹ������½ڵ㵽��β(�ǿձ�)\n");

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
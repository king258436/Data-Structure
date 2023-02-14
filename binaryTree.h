#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__  // 헤더파일 include 할때 이중포함 방지!

typedef int BTData;

typedef struct _bTreeNode {    // 이진 트리의 노드를 표현한 구조체
    BTData data;               // 노드 데이터
    struct _bTreeNode *left;   // 왼쪽 노드를 가리키는 포인터
    struct _bTreeNode *right;  // 오른쪽 노드를 가리키는 포인터
} BTreeNode;

BTreeNode *MakeBTreeNode(void);            // 노드의 생성
BTData GetData(BTreeNode *bt);             // 노드에 저장된 데이터를 반환
void SetData(BTreeNode *bt, BTData data);  // 노드에 데이터를 저장

BTreeNode *GetLeftSubTree(BTreeNode *bt);   // 매개변수에 넣은 노드의 왼쪽 서브트리 루트노드반환
BTreeNode *GetRightSubTree(BTreeNode *bt);  // 매개변수에 넣은 노드의 오른쪽 서브트리 루트노드반환

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);   // main 노드의 왼쪽 서브트리로 sub트리를 연결
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);  // main 노드의 오른쪽 서브트리로 sub트리를 연결

#endif
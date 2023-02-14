#include "BinaryTree.h"

#include <stdio.h>
#include <stdlib.h>

BTreeNode *MakeBTreeNode(void) {
    BTreeNode *nd = (BTreeNode *)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}  // 노드의 생성, 노드 왼쪽 오른쪽 null로 초기화, 데이터는 쓰래기값, 노드반환.

BTData GetData(BTreeNode *bt) { return bt->data; }             // 노드에 저장된 데이터를 반환
void SetData(BTreeNode *bt, BTData data) { bt->data = data; }  // 노드에 데이터를 저장

BTreeNode *GetLeftSubTree(BTreeNode *bt) { return bt->left; }    // 매개변수에 넣은 노드의 왼쪽 서브트리 루트노드반환
BTreeNode *GetRightSubTree(BTreeNode *bt) { return bt->right; }  // 매개변수에 넣은 노드의 오른쪽 서브트리 루트노드반환

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub) {
    if (main->left != NULL) free(main->left);  // main 노드의 왼쪽에 이미 연결되어있는 트리가 있으면 지워버리고 sub트리연결
    main->left = sub;
}  // main 노드의 왼쪽 서브트리로 sub트리를 연결
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub) {
    if (main->right != NULL) free(main->right);  // main 노드의 오른쪽에 이미 연결되어있는 트리가 있으면 지워버리고 sub트리연결
    main->right = sub;

}  // main 노드의 오른쪽 서브트리로 sub트리를 연결
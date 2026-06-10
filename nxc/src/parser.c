# This is a basic workflow to help you get started with Actions
#include <stdio.h>
#include <stdlib.h>

typedef struct ast_node {
    int type;
    struct ast_node* left;
    struct ast_node* right;
} ast_node_t;

ast_node_t* parse_graph_loop() {
    printf("[PARSER] Processing graph loop: foreach_edge...\n");
    ast_node_t* loop_node = (ast_node_t*)malloc(sizeof(ast_node_t));
    if (loop_node == NULL) return NULL;
    loop_node->type = 0x1A; 
    return loop_node;
}

int main() {
    printf("[COMPILER] Initializing nxc compiler token scanner...\n");
    ast_node_t* node = parse_graph_loop();
    if (node != NULL) {
        printf("[COMPILER] AST Node generated: 0x%X\n", node->type);
        free(node);
    }
    return 0;
}

name: CI

# Controls when the workflow will run
on:
  # Triggers the workflow on push or pull request events but only for the "main" branch
  push:
    branches: [ "main" ]
  pull_request:
    branches: [ "main" ]

  # Allows you to run this workflow manually from the Actions tab
  workflow_dispatch:

# A workflow run is made up of one or more jobs that can run sequentially or in parallel
jobs:
  # This workflow contains a single job called "build"
  build:
    # The type of runner that the job will run on
    runs-on: ubuntu-latest

    # Steps represent a sequence of tasks that will be executed as part of the job
    steps:
      # Checks-out your repository under $GITHUB_WORKSPACE, so your job can access it
      - uses: actions/checkout@v4

      # Runs a single command using the runners shell
      - name: Run a one-line script
        run: echo Hello, world!

      # Runs a set of commands using the runners shell
      - name: Run a multi-line script
        run: |
          echo Add other actions to build,
          echo test, and deploy your project.

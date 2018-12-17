#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "branch.h"
#include "texture.h"

#include "GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"

class Tree {
public:
	Tree();
	Tree(int depth, int height,  GLfloat init_x_pos=0.0f, GLfloat init_z_pos=0.0f, int init_strong_factor=1);


    void CreateCubeBranchMesh();
	void CreateCylinderBranchMesh();
	void buildTree(Branch* root_branch, int tree_depth, int tree_height, int total_depth);
	void renderTree(GLuint uniformModel, GLuint uniformView, GLuint uniformProjection, glm::mat4x4 projection);
	void keyControl(bool* keys);

	~Tree();

private:
	void growUpward(bool* keys);
	void growDownward(bool* keys);

	int depth = 3;
	int height = 3;
	int strong_factor = 1;
	GLfloat x_pos = 0.0f;
	GLfloat z_pos = 0.0f;
	std::vector<Branch*> branchList;
	std::vector<Mesh*> treeMeshList;
	Texture branchTexture;
};
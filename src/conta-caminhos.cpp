#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <stack>
#include <vector>
#include <string>
#include <cstring>

#include <graphviz/cgraph.h>

#define DEBUG FALSE

using namespace std;

int charsToInt(char* s) {
	char* pEnd;
	return strtol(s, &pEnd, 10);
}

int agxgetInt(Agnode_t* node, Agsym_t* atributo) {
	return charsToInt(agxget(node, atributo));
}

void printNodeDot(Agraph_t* g, Agnode_t* node) {
	cout << "\t" << agnameof(node) << " [" ;

	Agsym_t* atributo = NULL;
	int attrN = 0;
	while ((atributo = agnxtattr(g, AGNODE, atributo))) {
		int value = agxgetInt(node, atributo);;

		if (value != 0) { // prints only if value is meaningful
			attrN++;
			if (attrN > 1) {
				cout << "," ;
			}
			cout << atributo->name << "=" << value;
		}
	}

	cout<< "];" << endl;
}

void listGraphNodes(Agraph_t* g) {
	cout << "Grafo " << agnameof(g) << endl;
	cout << agnnodes(g) << " vertices" << endl;
	cout << agnedges(g) << " arestas" << endl;
	cout << (agisdirected(g) ? "" : "não ") << "direcionado" << endl;
	cout << (agissimple(g) ? "" : "não ") << "simples" << endl;
	cout << "vértices e atributos" << endl;

	for (Agnode_t *node=agfstnode(g); node; node=agnxtnode(g,node)){
		if (DEBUG) printNodeDot(g, node);
	}
}

void outAsDot(Agraph_t* g) {
	cout << "strict digraph countedPaths {\n";

	for (Agnode_t* node = agfstnode(g); node; node = agnxtnode(g, node)){
		// print name of node and attrs
		printNodeDot(g, node);
		// END print attrs

		// print out edges of the node
		for (Agedge_t* edge = agfstout(g, node); edge; edge = agnxtout(g, edge)){
			cout << "\t" << agnameof(agtail(edge))
			<< " -> " << agnameof(aghead(edge)) <<";\n";
		}
	}

	cout << "}\n";
}

// class Path ============================

class Path {
public:
	Agnode_t* node;
	Agsym_t* attr;

	Path (Agnode_t* n, Agsym_t* a) {
		node = n;
		attr = a;
	}

	void incrementAttr(Agsym_t* attribute) {
		int value = agxgetInt(node, attribute);
		value++;

		string valueStr = to_string(value);
		char* cstr = strdup(valueStr.c_str());

		agxset(node, attribute, (char *)valueStr.c_str());
		free(cstr);
	}

	vector<Path> allNextInPaths(Agraph_t* g) {
		vector<Path> nextInPaths;
		Agedge_t *inE;

		/*DEBUG LOG/*/
			clog << "All nexts in paths of node\n";
			if (DEBUG) printNodeDot(g, node);
			clog << "Are:\n";
		/*/DEBUG LOG*/

		// for all 'in neighbours' nodes, node <---- (inE->node)
		for (inE = agfstin(g, node); inE; inE = agnxtin(g, inE)) {
			// make a new Path with them  with the same labels as you
			// push the new Path on vector
			/*DEBUG LOG*/if (DEBUG) printNodeDot(g, inE->node);

			nextInPaths.push_back(Path(inE->node, attr));
		}

		return nextInPaths;
	}

	static
	void pushLabeledOnStack(Agraph_t* g, stack<Path>& pathS) {
		for (Agnode_t* node = agfstnode(g); node; node = agnxtnode(g,node)){
			/*DEBUG LOG*/clog << "\n\nChecking labels of " << agnameof(node) << "\n";
			Agsym_t* atributo = NULL;
			while ((atributo = agnxtattr(g, AGNODE, atributo))) {
				int value = agxgetInt(node, atributo);
				/*DEBUG LOG*/if (value > 0) clog << atributo->name << "=" << value << "; ";

				for (int i = 0; i < value; i++) {
					pathS.push(Path(node, atributo));
					/*DEBUG LOG*/clog << "\nPushed " << agnameof(pathS.top().node) << "\n";
				}
			}
		}
	}

};

// END class Path ============================

int main() {
	if (!DEBUG) {
		clog.rdbuf(NULL);
	}

	Agraph_t *g = agread(stdin, NULL);
	stack<Path> pathS;

	/*DEBUG LOG*/if (DEBUG) listGraphNodes(g);

	Path::pushLabeledOnStack(g, pathS);

	/*DEBUG LOG*/clog << "\n====\n" << "Stack size " << pathS.size() << "\n";

	while(!pathS.empty()) {
		Path currPath = pathS.top();
		pathS.pop();
		/*DEBUG LOG*/clog << endl << "--------------" << endl << "Stack pop " << agnameof(currPath.node) << "\n";

		vector<Path> nextInPaths = currPath.allNextInPaths(g);

		/*DEBUG LOG*/clog << "\n====\n" << "nextInPaths size " << nextInPaths.size() << "\n";

		// for each of the next paths
		for(size_t i = 0; i < nextInPaths.size(); ++i) {
			// increment value of currPath.attr in nextInPaths[i].node
			nextInPaths[i].incrementAttr(currPath.attr);

			/*DEBUG LOG/*/
				clog << endl << "Incremented " << agxget(nextInPaths[i].node, currPath.attr) << endl;
				if (DEBUG) printNodeDot(g, nextInPaths[i].node);
			/*/DEBUG LOG*/

			pathS.push(nextInPaths[i]);
		}
	}

	outAsDot(g);

	return 0;
}

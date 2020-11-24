#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{



    int SearchAgents_no = 30; //Number of search agents
    string Function_Name = "F10"; //Name of the test function that can be from F1 to F23 (Table 1,2,3 in the paper)
    int Max_iteration = 500; // Maximum numbef of iterations


    int dim,fobj;
    vector<int> lb,ub;
    double Best_score,Best_por,GWO_cg_curve;
    // Load details of the selected benchmark function

    Get_Fontion_details(Function_Name,lb,ub,dim,fobj);

    GWO(SearchAgents_no,Max_iteration,lb,ub,dim,fobj,Best_score,Best_score,Best_por,GWO_cg_curve)

    //méthode créant une figure windows avec un nom et des coord
    figure("Position",500,500,660,290);

    ///Draw search space

    //subplot(m,n,p) divides the current figure into an m-by-n grid and creates axes in the position specified by p. MATLAB® numbers subplot positions by row.
    //The first subplot is the first column of the first row, the second subplot is the second column of the first row, and so on. If axes exist in the specified position
    //, then this command makes the axes the current axes.
    subplot(1,2,1); //il faudrait la modif, pour passer la figure en param

    //La sémilogie (X,Y) trace les coordonnées x et y en utilisant une échelle linéaire sur l'axe x
    //et une échelle logarithmique en base 10 sur l'axe y.
    semilogy(GWO_cg_curve,"color","r");
    //semilogy(___,Name,Value) spécifie les propriétés des lignes en utilisant un ou plusieurs arguments de la paire Name,Value. Les propriétés s'appliquent à toutes les lignes tracées. Spécifiez les paires Nom,Valeur après tous les arguments de l'une des syntaxes précédentes.

    //title(titletext) adds the specified title to the current axes or standalone visualization
    title("parameter space");

    xlabel("x_1");
    ylabel("x_2");

    zlabel(Function_name,x_1,x_2 );

    ///Draw objective space

    subplot(1,2,2);
    semilogy(GWO_cg_curve,"Color","r");
    title("Objective space");
    xlabel("Iteration");
    ylabel("Best score obtained so far");

    //création d'une fenetre
    Fenetre("GWO");

    cout<<"The best solution obtained byGWO is : "<<Best_pos<<endl;
    cout<<"The best optimal value of the objective function is : "<<Best_score;

    return 0;
}

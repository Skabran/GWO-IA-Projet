/*%___________________________________________________________________%
%  Grey Wolf Optimizer (GWO) source codes version 1.0               %
%                                                                   %
%  Developed in MATLAB R2011b(7.13)                                 %
%                                                                   %
%  Author and programmer: Seyedali Mirjalili                        %
%                                                                   %
%         e-Mail: ali.mirjalili@gmail.com                           %
%                 seyedali.mirjalili@griffithuni.edu.au             %
%                                                                   %
%       Homepage: http://www.alimirjalili.com                       %
%                                                                   %
%   Main paper: S. Mirjalili, S. M. Mirjalili, A. Lewis             %
%               Grey Wolf Optimizer, Advances in Engineering        %
%               Software , in press,                                %
%               DOI: 10.1016/j.advengsoft.2013.12.007               %
%                                                                   %
%___________________________________________________________________%
*/

//This function initialize the first population of search agents
vector<<double> function initialisation(int SearchAgents_no, int dim, vector<double> ub, vector<double> lb)
{
    //tableau "Position" résultat renvoyé par la fonction.
    vector<double> Position;

    int Boundary_no = size(ub, 2);

    //If the boundaries of all variables are equal and user enter a signle
    //number for both ub and lb
    if(Boundary_no == 1)
    {
        Position.push_back(rand(SearchAgents_no,dim) .* (ub[0] - lb[0]) + lb[0]);
    }

    //If each variable has a different lb and ub
    if(Boundary_no > 1)
    {
        for(int i = 1; i< dim; ++i)
        {
            ub[i] = ub(i); //ub(i) méthode d'une autre class ?
            lb[i] = lb(i); //lb(i) méthode d'une autre class ?
            Position.push_back(rand(SearchAgents_no, 1).*(ub[i] - lb[i]) + lb[i]);
        }
    }
    return Position;
}


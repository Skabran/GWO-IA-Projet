

void GWO(??? SearchAgents_no,int Max_iter,vector<double> lb, vector<double> ub, int dim, ??? fobj, double &Alpha_Score, position &Alpha_pos, ??? Convergence_curve)
{
    vector<int> zeros(dim,0); //MatLab zeros(1,dim) cr�� un vector rempli de 0 d'une longueur (1,dim)
    // initialize alpha, beta, and delta_pos
Alpha_pos=zeros;
Alpha_score=INT_MAX; //change this to -inf for maximization problems

Beta_pos=zeros;
Beta_score=INT_MAX; //change this to -inf for maximization problems

Delta_pos=zeros;
Delta_score=INT_MAX; //change this to -inf for maximization problems

//Initialize the positions of search agents
Positions=initialization(SearchAgents_no,dim,ub,lb);

zeros.resize(Max_iter);
Convergence_curve=zeros;

int loopCounter=0;// Loop counter

// Main loop
while (loopCounter<Max_iter){
    for (int i=1; i<Position.size(); i++){


    // A TRADUIRE



       // Return back the search agents that go beyond the boundaries of the search space
        Flag4ub=Positions(i,:)>ub;
        Flag4lb=Positions(i,:)<lb;
        Positions(i,:)=(Positions(i,:).*(~(Flag4ub+Flag4lb)))+ub.*Flag4ub+lb.*Flag4lb;

        // Calculate objective function for each search agent
        fitness=fobj(Positions(i,:));

        // Update Alpha, Beta, and Delta
        if fitness<Alpha_score
            Alpha_score=fitness; // Update alpha
            Alpha_pos=Positions(i,:);
        end

        if fitness>Alpha_score && fitness<Beta_score
            Beta_score=fitness; // Update beta
            Beta_pos=Positions(i,:);
        end

        if fitness>Alpha_score && fitness>Beta_score && fitness<Delta_score
            Delta_score=fitness; // Update delta
            Delta_pos=Positions(i,:);
        end
    }


    a=2-l*((2)/Max_iter); // a decreases linearly fron 2 to 0

    % Update the Position of search agents including omegas
    for i=1:size(Positions,1)
        for j=1:size(Positions,2)

            r1=rand(); // r1 is a random number in [0,1]
            r2=rand(); // r2 is a random number in [0,1]

            A1=2*a*r1-a; // Equation (3.3)
            C1=2*r2; // Equation (3.4)

            D_alpha=abs(C1*Alpha_pos(j)-Positions(i,j)); // Equation (3.5)-part 1
            X1=Alpha_pos(j)-A1*D_alpha; % Equation (3.6)-part 1

            r1=rand();
            r2=rand();

            A2=2*a*r1-a; // Equation (3.3)
            C2=2*r2; // Equation (3.4)

            D_beta=abs(C2*Beta_pos(j)-Positions(i,j)); // Equation (3.5)-part 2
            X2=Beta_pos(j)-A2*D_beta; // Equation (3.6)-part 2

            r1=rand();
            r2=rand();

            A3=2*a*r1-a; // Equation (3.3)
            C3=2*r2; // Equation (3.4)

            D_delta=abs(C3*Delta_pos(j)-Positions(i,j)); // Equation (3.5)-part 3
            X3=Delta_pos(j)-A3*D_delta; // Equation (3.5)-part 3

            Positions(i,j)=(X1+X2+X3)/3;// Equation (3.7)

        end
    end
    loopCounter+=1;
    Convergence_curve(loopCounter)=Alpha_score;
}
}

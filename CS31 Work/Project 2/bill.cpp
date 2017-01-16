//
//  main.cpp
//  Energy_calculator
//
//  Created by Artiom Arutiunov on 1/15/16.
//  Copyright © 2016 Artiom Arutiunov. All rights reserved.

#include <iostream>
#include <string>
using namespace std;

int main()

{
    // declaring all variables used in program
    string customer_Name;
    string customer_Type;
    double energy_Used;
    double usage_Cost = 0; // initialized these variables to ensure stability of code
    double total_Cost = 0;
    
    
    // receiving infofmation from user
    
    
    cout << "Customer Name: ";
    getline ( cin, customer_Name );
    
    cout << "Energy used:(in kilowatt hours): ";
    cin >> energy_Used;
    cin.ignore(10000, '\n');
    
    cout << "Customer Type: ";
    // cin >> customer_Type;
    getline ( cin, customer_Type );
    
    cout << "---" << endl; // prints the hyphens before returning answer
    
    // controlling for invalid user input
    
    
    if (energy_Used < 0)
    {
        cout << "The energy usage reading must be nonnegative." << endl;
        return 0;
    }
    
    if (customer_Name == "")
    {
        cout << "You must enter a customer name." << endl;
        return 0;
    }
    
    if ((customer_Type != "Residential") && (customer_Type != "Business"))
    {
        cout << "The customer type is not valid." << endl;
        return 0;
    }
    
    
    // determining monthly bill for type of customer
    
    if (customer_Type == "Residential")
        
    {
        total_Cost = 14.95;
    }
    
    else if (customer_Type == "Business")
        
    {
        total_Cost = 19.95;
    }
    
    // determining Residential usage bill from kilowatts
    
    
    if ((customer_Type == "Residential") && (energy_Used <= 10))
        
        usage_Cost = energy_Used * 4.50; // price if kilowatts used < 10
    
    
    else if ((customer_Type == "Residential") && (energy_Used <= 20))
        
        usage_Cost = 45 + (energy_Used - 10) * 9.00; // adjusts for difference in price between 10 & 20
    
    
    else if ((customer_Type == "Residential") && (energy_Used > 20))
        
        usage_Cost = 135 + (energy_Used - 20) * 15.00; // adjusts for difference in price above 20 and  ensures that only the kilowatts above 20 are multiplied by $15
    
    
    // determining Business usage bill from kilowatts (same as above just with different constants)
    
    if ((customer_Type == "Business") && (energy_Used <= 10))
        
        usage_Cost = energy_Used * 7.50;
    
    
    else if ((customer_Type == "Business") && (energy_Used <= 20))
        
        usage_Cost = 75 + (energy_Used - 10) * 15.00;
    
    
    else if ((customer_Type == "Business") && (energy_Used > 20))
        
        usage_Cost = 225 + (energy_Used -20) * 20.00;
    
    
    // calculating total price
    
    total_Cost = total_Cost + usage_Cost;
    
    // final output
    
    cout.setf (ios::fixed); // ensures that the final price is stated with an ending 0
    cout.setf(ios::showpoint);
    cout.precision(2); // included at this point in code because ending 0's in kilowatts used is truncated
    
    cout << "The bill for " << customer_Name << " is $" << total_Cost << endl;
    
}

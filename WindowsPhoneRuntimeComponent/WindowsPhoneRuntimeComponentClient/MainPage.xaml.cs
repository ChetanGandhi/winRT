using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using WindowsPhoneRuntimeComponentClient.Resources;
using WindowsPhoneRuntimeComponent;

namespace WindowsPhoneRuntimeComponentClient
{
    public partial class MainPage : PhoneApplicationPage
    {
        // Constructor
        public MainPage()
        {
            InitializeComponent();
            WindowsPhoneRuntimeComponent.WindowsPhoneRuntimeComponentClass server = new WindowsPhoneRuntimeComponent.WindowsPhoneRuntimeComponentClass();
            int numberOne = 300;
            int numberTwo = 200;
            int sum = server.SumOfTwoInteger(numberOne, numberTwo);
            int subtraction = server.SubtractionOfTwoInteger(numberOne, numberTwo);

            textBlockOne.Text = "Sum is:" + sum;
            textBlockTwo.Text = "Subtraction is:" + subtraction;
        }
    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//Game is in example

namespace Exercises
{
    class Program
    {
        static void PrintIntArray(int[] numArray)
        {
            for(int i = 0; i < numArray.Length; ++i)
            {
                Console.WriteLine(numArray[i]);
            }
        }

        static void ReverseString(ref string given)
        {
            string reversestring = "";
            int length = given.Length - 1;
            while (length >= 0)
            {
                reversestring = reversestring + given[length];
                length--;
            }
            Console.WriteLine(reversestring);
            if(reversestring == given)
            {
                Console.WriteLine("is a palandrome");
            }
        }

        class player
        {
            public string name;
            public int guess;
        }

        //static player ThePriceIsFuck(player[] Players, int correctNumber)
        //{
        //    //int Pcont = 0;
        //    player[] temp = Players;
        //    for(int i = 0; i < Players.Length; ++i)
        //    {
        //        if (Players[i].guess == correctNumber)
        //        {
        //            return Players[i];

        //            //temp[Pcont] = Players[i];
        //            //++Pcont; 
        //        }
        //    }


        //    //for(int b = 0; b < Pcont; ++b)
        //    //{
        //    //    return temp[b];
        //    //}
        //}

        static void Main(string[] args)
        {
            player[] TestPlayers = new player[5];
            TestPlayers[0] = new player();
            TestPlayers[0].name = "John";
            TestPlayers[0].guess = 1;
            TestPlayers[1] = new player();
            TestPlayers[1].name = "Price";
            TestPlayers[1].guess = 12;
            TestPlayers[2] = new player();
            TestPlayers[2].name = "Julie";
            TestPlayers[2].guess = 8;
            TestPlayers[3] = new player();
            TestPlayers[3].name = "Francesca";
            TestPlayers[3].guess = 9;
            TestPlayers[4] = new player();
            TestPlayers[4].name = "Philipe";
            TestPlayers[4].guess = 4;

            int[] missprint = {5,7,9};

            string StringTest1 = "Hello again.";
            string StringTest2 = "racecar";
            string StringTest3 = "madam";
            string StringTest4 = "bat";

            Console.WriteLine(StringTest1);

            PrintIntArray(missprint);

            ReverseString(ref StringTest1);
            ReverseString(ref StringTest2);
            ReverseString(ref StringTest3);
            ReverseString(ref StringTest4);

            Console.ReadLine();
        }
    }
}

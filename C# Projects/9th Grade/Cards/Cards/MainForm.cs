/*
 * Created by SharpDevelop.
 * User: zala2
 * Date: 25.9.2018 г.
 * Time: 09:15 ч.
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace Cards
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	public partial class MainForm : Form
	{
		public MainForm()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		
		void CheckClick(object sender, EventArgs e)
		{
			var cards =  new Dictionary<char, string>();
			var suits =  new Dictionary<char, string>();
			cards['K'] = "King";
			cards['Q'] = "Queen";
			cards['J'] =  "Jack";
			suits['D'] = "Diamonds";
			suits['H'] = "Hearts";
			suits['S'] = "Spades";
			suits['C'] = "Clubs";
			string karta = textBox1.Text.ToUpper();
			string suit = textBox2.Text.ToUpper();
			if(karta.Length != 1 || suit.Length != 1)
			{
				MessageBox.Show("Invalid input");
			}
			else
			{

				if(!cards.ContainsKey(Convert.ToChar(karta)) || !suits.ContainsKey(Convert.ToChar(suit)))
				{
					MessageBox.Show("No such card exists");
				}
				else
					label4.Text = cards[Convert.ToChar(karta)] + " of " + suits[Convert.ToChar(suit)];
			}
		}
	}
}

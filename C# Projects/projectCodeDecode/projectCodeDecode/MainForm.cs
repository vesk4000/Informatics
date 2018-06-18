/*
 * Created by SharpDevelop.
 * User: zala2
 * Date: 18.6.2018 г.
 * Time: 11:08 ч.
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace projectCodeDecode
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
		void Button1Click(object sender, EventArgs e)
		{
			string alphabet = "абвгдежзийклмнопрстуфхцчшщьъюя";
			//labelResult.Text = Convert.ToString(alphabet.Length);
			if(textBoxFrom.Text.Length != 1 || textBoxTo.Text.Length != 1)
				return;
			char from = Convert.ToChar(textBoxFrom.Text);
			char to = Convert.ToChar(textBoxTo.Text);
			int n;
			int l1 = alphabet.IndexOf(from) + 1;
			int l2 = alphabet.IndexOf(to) + 1;
			if(l1 > l2)
				l2 += 30;
			n = l2 - l1;
			labelResult.Text = "";
			string or = textBoxInput.Text;
			textBoxInput.Text = textBoxInput.Text.ToLower();
			for(int i = 0;i < textBoxInput.Text.Length; ++i)
			{
				bool flag = false;
				for(int j = 0;j < alphabet.Length; ++j)
				{
					if(textBoxInput.Text[i] == alphabet[j])
						flag = true;
				}
				if(flag)
				{
					char ans;
					if(alphabet.IndexOf(textBoxInput.Text[i]) + n > 29)
						ans = alphabet[ alphabet.IndexOf(textBoxInput.Text[i]) + n - 30 ];
					else
						ans = alphabet[ alphabet.IndexOf(textBoxInput.Text[i]) + n];
					labelResult.Text = labelResult.Text + ans;
				}
				else
					labelResult.Text = labelResult.Text + textBoxInput.Text[i];
			}
			textBoxInput.Text = or;
		}
		void Button2Click(object sender, EventArgs e)
		{
			string alphabet = "абвгдежзийклмнопрстуфхцчшщьъюя";
			//labelResult.Text = Convert.ToString(alphabet.Length);
			if(textBoxFrom2.Text.Length != 1 || textBoxTo2.Text.Length != 1)
				return;
			char from = Convert.ToChar(textBoxFrom2.Text);
			char to = Convert.ToChar(textBoxTo2.Text);
			int n;
			int l1 = alphabet.IndexOf(from) + 1;
			int l2 = alphabet.IndexOf(to) + 1;
			if(l1 > l2)
				l2 += 30;
			n = l2 - l1;
			labelResult2.Text = "";

			for(int i = 0;i < textBoxInput2.Text.Length; ++i)
			{
				bool flag = false;
				for(int j = 0;j < alphabet.Length; ++j)
				{
					if(textBoxInput2.Text[i] == alphabet[j])
						flag = true;
				}
				if(flag)
				{
					char ans;
					if(alphabet.IndexOf(textBoxInput2.Text[i]) - n < 0)
						ans = alphabet[ alphabet.IndexOf(textBoxInput2.Text[i]) - n + 30 ];
					else
						ans = alphabet[ alphabet.IndexOf(textBoxInput2.Text[i]) - n];
					labelResult2.Text = labelResult2.Text + ans;
				}
				else
					labelResult2.Text = labelResult2.Text + textBoxInput2.Text[i];
				
			}
			
			
		}
	}
}

/*
 * Created by SharpDevelop.
 * User: zala2
 * Date: 18.9.2018 г.
 * Time: 09:27 ч.
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace ClickCounter
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
		private int num = 0;
		void Button1Click(object sender, EventArgs e)
		{
			num++;
			label2.Text = Convert.ToString(num);
		}
		void Button2Click(object sender, EventArgs e)
		{
			num = 0;
			label2.Text = Convert.ToString(num);
		}
		
	}
}

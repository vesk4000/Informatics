/*
 * Created by SharpDevelop.
 * User: zala2
 * Date: 2.10.2018 г.
 * Time: 09:10 ч.
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace WindScale
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
			string s = textBox1.Text;
			double d = Convert.ToDouble(s);
			if(d < 0)
				MessageBox.Show("Невалидни числови данни", "O-o");
			else
			{
				int step = 0;
				if(d >= 13.9)
					step = 7;
				if(d >= 17.2)
					step = 8;
				if(d >= 20.8)
					step = 9;
				if(d >= 24.5)
					step = 10;
				if(d >= 28.5)
					step = 11;
				if(d >= 32.7)
					step = 12;
				label3.Text = Convert.ToString(step);
				string[] name = new string[13];
				string[] description = new string[13];
				name[7] = "Засилен вятър High wind";
				name[8] = "Силен вятър, буря/Gale";
				name[9] = "Много силен вятър/Strong gale";
				name[10] = "Буря, щорм/Storm, whole gale";
				name[11] = "Силна буря/Violent storm";
				name[12] = "Ураган";
				description[7] = "Огъват се неголеми дървета, големи клони, стволовете на дърветата се разлюляват. Ходенето срещу вятъра се затруднява.Чува се свистене на вятъра около сградите и неподвижните предмети.";
				description[8] = "Клатят се големи стволове, огъват се големи дървета, чупят се тънки клончета и сухи клони. Движението срещу вятъра значително се забавя.";
				description[9] = "Наблюдават се неголеми повреди на постройките (вдигане на керемиди, капаци). Чупят се големи клони на дърветата. Отместват се леки предмети от местата им.";
				description[10] = "Наблюдават се разрушения по покривите на постройките. Някои дървета могат да бъдат повалени.";
				description[11] = "Наблюдават се големи разрушения на постройките. Чупят се стъблата на дърветата.";
				description[12] = "Ураган. Наблюдават се катастрофални разрушения, отнасяне нацели покриви на сгради. Дърветата се изскубват с корените.";
				label5.Text = name[step];
				label7.Text = description[step];
			}
		}
	}
}

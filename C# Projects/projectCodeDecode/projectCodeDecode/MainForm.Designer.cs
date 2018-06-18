/*
 * Created by SharpDevelop.
 * User: zala2
 * Date: 18.6.2018 г.
 * Time: 11:08 ч.
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace projectCodeDecode
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private System.Windows.Forms.TabControl tabControl1;
		private System.Windows.Forms.TabPage tabPage1;
		private System.Windows.Forms.Label labelResult;
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.TextBox textBoxTo;
		private System.Windows.Forms.Label labelText4;
		private System.Windows.Forms.TextBox textBoxFrom;
		private System.Windows.Forms.Label labelText3;
		private System.Windows.Forms.Label labelText2;
		private System.Windows.Forms.TextBox textBoxInput;
		private System.Windows.Forms.Label labelText1;
		private System.Windows.Forms.TabPage tabPage2;
		private System.Windows.Forms.Label labelResult2;
		private System.Windows.Forms.Button button2;
		private System.Windows.Forms.TextBox textBoxTo2;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.TextBox textBoxFrom2;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.TextBox textBoxInput2;
		private System.Windows.Forms.Label label5;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			this.tabControl1 = new System.Windows.Forms.TabControl();
			this.tabPage1 = new System.Windows.Forms.TabPage();
			this.labelResult = new System.Windows.Forms.Label();
			this.button1 = new System.Windows.Forms.Button();
			this.textBoxTo = new System.Windows.Forms.TextBox();
			this.labelText4 = new System.Windows.Forms.Label();
			this.textBoxFrom = new System.Windows.Forms.TextBox();
			this.labelText3 = new System.Windows.Forms.Label();
			this.labelText2 = new System.Windows.Forms.Label();
			this.textBoxInput = new System.Windows.Forms.TextBox();
			this.labelText1 = new System.Windows.Forms.Label();
			this.tabPage2 = new System.Windows.Forms.TabPage();
			this.labelResult2 = new System.Windows.Forms.Label();
			this.button2 = new System.Windows.Forms.Button();
			this.textBoxTo2 = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.textBoxFrom2 = new System.Windows.Forms.TextBox();
			this.label3 = new System.Windows.Forms.Label();
			this.label4 = new System.Windows.Forms.Label();
			this.textBoxInput2 = new System.Windows.Forms.TextBox();
			this.label5 = new System.Windows.Forms.Label();
			this.tabControl1.SuspendLayout();
			this.tabPage1.SuspendLayout();
			this.tabPage2.SuspendLayout();
			this.SuspendLayout();
			// 
			// tabControl1
			// 
			this.tabControl1.Controls.Add(this.tabPage1);
			this.tabControl1.Controls.Add(this.tabPage2);
			this.tabControl1.Location = new System.Drawing.Point(13, 13);
			this.tabControl1.Name = "tabControl1";
			this.tabControl1.SelectedIndex = 0;
			this.tabControl1.Size = new System.Drawing.Size(663, 261);
			this.tabControl1.TabIndex = 0;
			// 
			// tabPage1
			// 
			this.tabPage1.Controls.Add(this.labelResult);
			this.tabPage1.Controls.Add(this.button1);
			this.tabPage1.Controls.Add(this.textBoxTo);
			this.tabPage1.Controls.Add(this.labelText4);
			this.tabPage1.Controls.Add(this.textBoxFrom);
			this.tabPage1.Controls.Add(this.labelText3);
			this.tabPage1.Controls.Add(this.labelText2);
			this.tabPage1.Controls.Add(this.textBoxInput);
			this.tabPage1.Controls.Add(this.labelText1);
			this.tabPage1.Location = new System.Drawing.Point(4, 22);
			this.tabPage1.Name = "tabPage1";
			this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
			this.tabPage1.Size = new System.Drawing.Size(655, 235);
			this.tabPage1.TabIndex = 0;
			this.tabPage1.Text = "Кодиране";
			this.tabPage1.UseVisualStyleBackColor = true;
			// 
			// labelResult
			// 
			this.labelResult.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.labelResult.Location = new System.Drawing.Point(6, 138);
			this.labelResult.Name = "labelResult";
			this.labelResult.Size = new System.Drawing.Size(456, 79);
			this.labelResult.TabIndex = 9;
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(469, 79);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(100, 29);
			this.button1.TabIndex = 8;
			this.button1.Text = "Кодирай";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.Button1Click);
			// 
			// textBoxTo
			// 
			this.textBoxTo.Location = new System.Drawing.Point(538, 49);
			this.textBoxTo.Name = "textBoxTo";
			this.textBoxTo.Size = new System.Drawing.Size(31, 20);
			this.textBoxTo.TabIndex = 7;
			// 
			// labelText4
			// 
			this.labelText4.Location = new System.Drawing.Point(468, 52);
			this.labelText4.Name = "labelText4";
			this.labelText4.Size = new System.Drawing.Size(76, 23);
			this.labelText4.TabIndex = 6;
			this.labelText4.Text = "се заменя с:";
			// 
			// textBoxFrom
			// 
			this.textBoxFrom.Location = new System.Drawing.Point(511, 26);
			this.textBoxFrom.Name = "textBoxFrom";
			this.textBoxFrom.Size = new System.Drawing.Size(30, 20);
			this.textBoxFrom.TabIndex = 5;
			// 
			// labelText3
			// 
			this.labelText3.Location = new System.Drawing.Point(468, 29);
			this.labelText3.Name = "labelText3";
			this.labelText3.Size = new System.Drawing.Size(49, 23);
			this.labelText3.TabIndex = 4;
			this.labelText3.Text = "Буква:";
			// 
			// labelText2
			// 
			this.labelText2.Location = new System.Drawing.Point(6, 115);
			this.labelText2.Name = "labelText2";
			this.labelText2.Size = new System.Drawing.Size(100, 23);
			this.labelText2.TabIndex = 2;
			this.labelText2.Text = "Кодиран текст:";
			// 
			// textBoxInput
			// 
			this.textBoxInput.Location = new System.Drawing.Point(6, 29);
			this.textBoxInput.Multiline = true;
			this.textBoxInput.Name = "textBoxInput";
			this.textBoxInput.Size = new System.Drawing.Size(456, 79);
			this.textBoxInput.TabIndex = 1;
			// 
			// labelText1
			// 
			this.labelText1.Location = new System.Drawing.Point(6, 3);
			this.labelText1.Name = "labelText1";
			this.labelText1.Size = new System.Drawing.Size(108, 23);
			this.labelText1.TabIndex = 0;
			this.labelText1.Text = "Текст за кодиране:";
			// 
			// tabPage2
			// 
			this.tabPage2.Controls.Add(this.labelResult2);
			this.tabPage2.Controls.Add(this.button2);
			this.tabPage2.Controls.Add(this.textBoxTo2);
			this.tabPage2.Controls.Add(this.label2);
			this.tabPage2.Controls.Add(this.textBoxFrom2);
			this.tabPage2.Controls.Add(this.label3);
			this.tabPage2.Controls.Add(this.label4);
			this.tabPage2.Controls.Add(this.textBoxInput2);
			this.tabPage2.Controls.Add(this.label5);
			this.tabPage2.Location = new System.Drawing.Point(4, 22);
			this.tabPage2.Name = "tabPage2";
			this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
			this.tabPage2.Size = new System.Drawing.Size(655, 235);
			this.tabPage2.TabIndex = 1;
			this.tabPage2.Text = "Декодиране";
			this.tabPage2.UseVisualStyleBackColor = true;
			// 
			// labelResult2
			// 
			this.labelResult2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
			this.labelResult2.Location = new System.Drawing.Point(6, 138);
			this.labelResult2.Name = "labelResult2";
			this.labelResult2.Size = new System.Drawing.Size(456, 79);
			this.labelResult2.TabIndex = 18;
			// 
			// button2
			// 
			this.button2.Location = new System.Drawing.Point(469, 79);
			this.button2.Name = "button2";
			this.button2.Size = new System.Drawing.Size(100, 29);
			this.button2.TabIndex = 17;
			this.button2.Text = "Декодиране";
			this.button2.UseVisualStyleBackColor = true;
			this.button2.Click += new System.EventHandler(this.Button2Click);
			// 
			// textBoxTo2
			// 
			this.textBoxTo2.Location = new System.Drawing.Point(538, 49);
			this.textBoxTo2.Name = "textBoxTo2";
			this.textBoxTo2.Size = new System.Drawing.Size(31, 20);
			this.textBoxTo2.TabIndex = 16;
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(468, 52);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(76, 23);
			this.label2.TabIndex = 15;
			this.label2.Text = "се заменя с:";
			// 
			// textBoxFrom2
			// 
			this.textBoxFrom2.Location = new System.Drawing.Point(511, 26);
			this.textBoxFrom2.Name = "textBoxFrom2";
			this.textBoxFrom2.Size = new System.Drawing.Size(30, 20);
			this.textBoxFrom2.TabIndex = 14;
			// 
			// label3
			// 
			this.label3.Location = new System.Drawing.Point(468, 29);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(49, 23);
			this.label3.TabIndex = 13;
			this.label3.Text = "Буква:";
			// 
			// label4
			// 
			this.label4.Location = new System.Drawing.Point(6, 115);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(100, 23);
			this.label4.TabIndex = 12;
			this.label4.Text = "Декодиран текст:";
			// 
			// textBoxInput2
			// 
			this.textBoxInput2.Location = new System.Drawing.Point(6, 29);
			this.textBoxInput2.Multiline = true;
			this.textBoxInput2.Name = "textBoxInput2";
			this.textBoxInput2.Size = new System.Drawing.Size(456, 79);
			this.textBoxInput2.TabIndex = 11;
			// 
			// label5
			// 
			this.label5.Location = new System.Drawing.Point(6, 3);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(108, 23);
			this.label5.TabIndex = 10;
			this.label5.Text = "Кодиран текст:";
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(688, 286);
			this.Controls.Add(this.tabControl1);
			this.Name = "MainForm";
			this.Text = "projectCodeDecode";
			this.tabControl1.ResumeLayout(false);
			this.tabPage1.ResumeLayout(false);
			this.tabPage1.PerformLayout();
			this.tabPage2.ResumeLayout(false);
			this.tabPage2.PerformLayout();
			this.ResumeLayout(false);

		}
	}
}

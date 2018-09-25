/*
 * Created by SharpDevelop.
 * User: zala2
 * Date: 25.9.2018 г.
 * Time: 09:15 ч.
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace Cards
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private System.Windows.Forms.GroupBox groupBox1;
		private System.Windows.Forms.TextBox textBox2;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.TextBox textBox1;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Button Check;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Label label4;
		
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
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.textBox2 = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.textBox1 = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.Check = new System.Windows.Forms.Button();
			this.label3 = new System.Windows.Forms.Label();
			this.label4 = new System.Windows.Forms.Label();
			this.groupBox1.SuspendLayout();
			this.SuspendLayout();
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.textBox2);
			this.groupBox1.Controls.Add(this.label2);
			this.groupBox1.Controls.Add(this.textBox1);
			this.groupBox1.Controls.Add(this.label1);
			this.groupBox1.Location = new System.Drawing.Point(13, 13);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(92, 90);
			this.groupBox1.TabIndex = 0;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "Card Code";
			// 
			// textBox2
			// 
			this.textBox2.Location = new System.Drawing.Point(50, 50);
			this.textBox2.Name = "textBox2";
			this.textBox2.Size = new System.Drawing.Size(23, 20);
			this.textBox2.TabIndex = 3;
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(8, 50);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(35, 23);
			this.label2.TabIndex = 2;
			this.label2.Text = "Suit: ";
			// 
			// textBox1
			// 
			this.textBox1.Location = new System.Drawing.Point(49, 20);
			this.textBox1.Name = "textBox1";
			this.textBox1.Size = new System.Drawing.Size(24, 20);
			this.textBox1.TabIndex = 1;
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(8, 23);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(35, 23);
			this.label1.TabIndex = 0;
			this.label1.Text = "Card: ";
			// 
			// Check
			// 
			this.Check.Location = new System.Drawing.Point(111, 13);
			this.Check.Name = "Check";
			this.Check.Size = new System.Drawing.Size(75, 23);
			this.Check.TabIndex = 1;
			this.Check.Text = "Check";
			this.Check.UseVisualStyleBackColor = true;
			this.Check.Click += new System.EventHandler(this.CheckClick);
			// 
			// label3
			// 
			this.label3.Location = new System.Drawing.Point(112, 43);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(141, 23);
			this.label3.TabIndex = 2;
			this.label3.Text = "The full name of the card is:";
			// 
			// label4
			// 
			this.label4.Location = new System.Drawing.Point(252, 43);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(124, 23);
			this.label4.TabIndex = 3;
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(388, 120);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.Check);
			this.Controls.Add(this.groupBox1);
			this.Name = "MainForm";
			this.Text = "Cards";
			this.groupBox1.ResumeLayout(false);
			this.groupBox1.PerformLayout();
			this.ResumeLayout(false);

		}
	}
}

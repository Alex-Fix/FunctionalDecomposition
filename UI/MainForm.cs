using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UI
{
    public partial class MainForm : Form
    {
        private readonly Random _random;

        List<List<int>> MatrixA;
        List<List<int>> MatrixA1;
        List<List<int>> MatrixA2;
        List<List<int>> MatrixB2;
        List<List<int>> MatrixB1;
        List<List<int>> MatrixC1;

        public MainForm()
        {
            InitializeComponent();
            DataGrid.AllowUserToAddRows = false;
            DataGrid.AllowUserToDeleteRows = false;
            DataGrid.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.AllCells;
            SetDataGridSize(ARadio.Name);
            _random = new Random(Guid.NewGuid().ToByteArray().Sum(e => e));
        }

        private void SetDataGridSize(string name, bool clearDataGrid = false)
        {
            var dimention = (int)DimensionNUD.Value;
            var row = dimention;
            var column = 1;
            if (name == "ARadio" || name == "A1Radio" || name == "A2Radio" || name == "B2Radio")
                column = dimention;

            DataGrid.RowCount = row;
            DataGrid.ColumnCount = column;
            foreach (DataGridViewRow dataRow in DataGrid.Rows)
                dataRow.HeaderCell.Value = (dataRow.Index + 1).ToString();
            foreach (DataGridViewColumn dataColumn in DataGrid.Columns)
                dataColumn.HeaderCell.Value = (dataColumn.Index + 1).ToString();

            if (clearDataGrid)
                ClearDataGrid();
        }

        private void ClearDataGrid()
        {
            foreach (DataGridViewRow dataRow in DataGrid.Rows)
                foreach (DataGridViewCell dataCell in dataRow.Cells)
                    dataCell.Value = DBNull.Value;
        }

        private string GetCheckedRatioName()
        {
            string radioName;
            if (ARadio.Checked)
                radioName = ARadio.Name;
            else if (A1Radio.Checked)
                radioName = A1Radio.Name;
            else if (A2Radio.Checked)
                radioName = A2Radio.Name;
            else if (B2Radio.Checked)
                radioName = B2Radio.Name;
            else if (B1Radio.Checked)
                radioName = B1Radio.Name;
            else if (C1Radio.Checked)
                radioName = C1Radio.Name;
            else
                radioName = ARadio.Name;
            return radioName;
        }

        private void DimentionNUDChanged(object sender, EventArgs e)
        {
            var radioName = GetCheckedRatioName();
            SetDataGridSize(radioName);
        }

        private void RadioCheckedChanged(object sender, EventArgs e)
        {
            if (!(sender is RadioButton))
                return;
            var radio = (RadioButton)sender;
            if (!radio.Checked)
                return;

            SetDataGridSize(radio.Name, true);
        }

        private void ClearBtnClick(object sender, EventArgs e) => ClearDataGrid();

        private void FillMatrixRandomly(object sender, EventArgs e)
        {
            foreach (DataGridViewRow dataRow in DataGrid.Rows)
                foreach (DataGridViewCell dataCell in dataRow.Cells)
                    dataCell.Value = _random.Next(1, 100).ToString();
        }

        private void FillMatrixClick(object sender, EventArgs e)
        {
            var radioName = GetCheckedRatioName();
            FillMatrix(radioName);
        }

        private bool DataGridIsValied()
        {
            var sb = new StringBuilder();
            var valid = true;
            foreach (DataGridViewRow dataRow in DataGrid.Rows)
                foreach (DataGridViewCell dataCell in dataRow.Cells)
                    try
                    {
                        var cellText = (string)dataCell.Value;
                        int cellValue = int.Parse(cellText);
                        if (cellValue <= 0)
                            throw new ArgumentException();
                    }
                    catch
                    {
                        sb.AppendLine($"Комірка [Р:К]=[{dataRow.Index + 1}:{dataCell.ColumnIndex + 1}] є не коректною");
                        valid = false;
                    }

            if (!valid)
                MessageBox.Show(sb.ToString());

            return valid;
        }

        private List<List<int>> CreateAndFillMatrix(string radioName)
        {
            List<List<int>> matrix = null;
            if (ARadio.Checked)
            {
                MatrixA = new List<List<int>>();
                matrix = MatrixA;
            }
            else if (A1Radio.Checked)
            {
                MatrixA1 = new List<List<int>>();
                matrix = MatrixA1;
            }
            else if (A2Radio.Checked)
            {
                MatrixA2 = new List<List<int>>();
                matrix = MatrixA2;
            }
            else if (B2Radio.Checked)
            {
                MatrixB2 = new List<List<int>>();
                matrix = MatrixB2;
            }
            else if (B1Radio.Checked)
            {
                MatrixB1 = new List<List<int>>();
                matrix = MatrixB1;
            }
            else if (C1Radio.Checked)
            {
                MatrixC1 = new List<List<int>>();
                matrix = MatrixC1;
            }

            return matrix;
        }

        private void FillMatrix(string radioName)
        {
            var isValid = DataGridIsValied();
            if (!isValid)
                return;

            var matrix = CreateAndFillMatrix(radioName);

            foreach (DataGridViewRow dataRow in DataGrid.Rows)
            {
                var row = new List<int>();
                foreach (DataGridViewCell dataCell in dataRow.Cells)
                    row.Add(int.Parse((string)dataCell.Value));
                matrix.Add(row);
            }
        }

        private bool ValidateAllMatrixes()
        {
            var isValid = true;
            var dimention = (int)DimensionNUD.Value;
            if (MatrixA == null || MatrixA.Count() != dimention || MatrixA.Any(c => c.Count() != dimention) || MatrixA.Any(c => c.Any(cell => cell <= 0)) ||
                MatrixA1 == null || MatrixA1.Count() != dimention || MatrixA1.Any(c => c.Count() != dimention) || MatrixA1.Any(c => c.Any(cell => cell <= 0)) ||
                MatrixA2 == null || MatrixA2.Count() != dimention || MatrixA2.Any(c => c.Count() != dimention) || MatrixA2.Any(c => c.Any(cell => cell <= 0)) ||
                MatrixB2 == null || MatrixB2.Count() != dimention || MatrixB2.Any(c => c.Count() != dimention) || MatrixB2.Any(c => c.Any(cell => cell <= 0)) ||
                MatrixB1 == null || MatrixB1.Count() != dimention || MatrixB1.Any(c => c.Count() != 1) || MatrixB1.Any(c => c.Any(cell => cell <= 0)) ||
                MatrixC1 == null || MatrixC1.Count() != dimention || MatrixC1.Any(c => c.Count() != 1) || MatrixC1.Any(c => c.Any(cell => cell <= 0)))
                isValid = false;

            if (!isValid)
                MessageBox.Show("Матриці не пройшли валідацію!");

            return isValid;
        }

        private void CalculateBtnClick(object sender, EventArgs e)
        {
            var isValid = ValidateAllMatrixes();
            if (!isValid)
                return;

            using (var stream = new StreamWriter("matrixes.txt", false, Encoding.ASCII))
            {

                var sb = new StringBuilder();
                sb.AppendLine(((int)DimensionNUD.Value).ToString());
                foreach (var row in MatrixA)
                    sb.AppendLine(string.Join("\r\n", row));
                foreach (var row in MatrixA1)
                    sb.AppendLine(string.Join("\r\n", row));
                foreach (var row in MatrixA2)
                    sb.AppendLine(string.Join("\r\n", row));
                foreach (var row in MatrixB2)
                    sb.AppendLine(string.Join("\r\n", row));
                foreach (var row in MatrixB1)
                    sb.AppendLine(string.Join("\r\n", row));
                foreach (var row in MatrixC1)
                    sb.AppendLine(string.Join("\r\n", row));

                stream.Write(sb.ToString());
            }

            Process.Start("mpiexec", " -n 3 Laba2").WaitForExit();

            string result = "X = ";
            using (var stream = new StreamReader("result.txt"))
                result += stream.ReadToEnd();

            long maxTime = 0;
            using (var stream = new StreamReader("time0.txt"))
                maxTime = long.Parse(stream.ReadToEnd());
            using (var stream = new StreamReader("time1.txt"))
            {
                var maxTime2 = long.Parse(stream.ReadToEnd());
                if (maxTime < maxTime2)
                    maxTime = maxTime2;
            }
            using (var stream = new StreamReader("time2.txt"))
            {
                var maxTime3 = long.Parse(stream.ReadToEnd());
                if (maxTime < maxTime3)
                    maxTime = maxTime3;
            }

            result += "Max time = " + (maxTime/1000).ToString()+ " ms";

            MessageBox.Show(result);
        }
    }
}

using System.Reflection;
using System.Windows.Forms;

public static class UIOptimizer
{
    public static void EnableDoubleBuffering(Control root)
    {
        if (root == null) return;

        var prop = typeof(Control).GetProperty(
            "DoubleBuffered",
            BindingFlags.NonPublic | BindingFlags.Instance
        );

        prop?.SetValue(root, true, null);

        foreach (Control child in root.Controls)
        {
            EnableDoubleBuffering(child);
        }
    }
}
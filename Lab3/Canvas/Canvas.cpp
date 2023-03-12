#include "Canvas.h"

Canvas::Canvas(int width,int height)
{
    n=width;
    m=height;
    this->Clear();
}

void Canvas::Clear(){

    int i, j;
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            a[i][j]=0;

}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    if (x1 < 0 || x1 > n || y1 < 0 || y1 > m|| x2 < 0 || x2 > n || y1 < 0 || y1 > m) return;
    int dx, dy, sx, sy, error, e2;
    dx = abs(x2 - x1);
    sx = (x1 < x2) ? 1 : -1;
    dy = -abs(y2 - y1);
    sy = (y1 < y2) ? 1 : -1;
    error = dx + dy;

    while (true){
        a[y1][x1]=ch;
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * error;
        if (e2 >= dy){
            if (x1 == x2) break;
            error = error + dy;
            x1 = x1 + sx;
        }
        if (e2 <= dx){
            if (y1 == y2) break;
            error = error + dx;
            y1 = y1 + sy;
        }
    }
}

void Canvas::Print()
{
    int i, j;
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
            if (a[i][j])
               std::cout<<a[i][j]<<" ";
               else
               std::cout<<'.'<<" ";

        std::cout<<'\n';
    }
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x<0 || x>n || y<0 || y>m) return;
    a[y][x]='ch';
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{

    if (x-ray < 0 || x+ray > n || y-ray < 0 || y+ray > m) return;
    this->Clear();
    int u, v, e, q, b;
    //e(u  ,v  ) = r*r - u*u + u - v*v
    //             e(r  ,0  ) = r
    //e(u  ,v+1) = e(u  ,v  ) - 2*v - 1 = e(u  ,v  ) - a(u,v)
    //e(u-1,v+1) = e(u  ,v+1) + 2*u     = e(u  ,v+1) + b(u,v)
    //
    //a(u  ,v  ) = 2*v + 1        ; b(u  ,v  ) = 2*u
    //             a(r  ,0  ) = 1 ;              b(u  ,v  ) = 2*r
    //a(u  ,v+1) = a(u  ,v  ) + 2 ; b(u  ,v+1) = b(u  ,v  )
    //a(u-1,v+1) = a(u  ,v  )     ; b(u-1,v+1) = b(u  ,v  ) - 2
    for (q = 1, b = (e = u = ray) * 2, v = 0; u > v + 1;) {
        a[x + u][y + v]=ch; a[x + v][y + u]=ch;
        a[x - u][y + v]=ch; a[x - v][y + u]=ch;
        a[x + u][y - v]=ch; a[x + v][y - u]=ch;
        a[x - u][y - v]=ch; a[x - v][y - u]=ch;
        v++; e -= q; q += 2; // above
        if (e <= 0) {
            u--; e += b; b -= 2; // diagonal
        }
    }
    if (u > v) { // penultimate pixel
        a[x + u][y + v]=ch; a[x + v][y + u]=ch;
        a[x - u][y + v]=ch; a[x - v][y + u]=ch;
        a[x + u][y - v]=ch; a[x + v][y - u]=ch;
        a[x - u][y - v]=ch; a[x - v][y - u]=ch;
        v++; // above
        if (e <= 0 &&
            --u == v); // diagonal: can draw last pixel
        else return; // not diagonal: don't draw last pixel
    }
    // draw last pixel where (u == v)
    a[x + u][y + u]=ch;
    a[x - u][y + u]=ch;
    a[x + u][y - u]=ch;
    a[x - u][y - u]=ch;
}


void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    if (x-ray < 0 || x+ray > n || y-ray < 0 || y+ray > m) return;
    this->DrawCircle(x, y, ray, ch);

    int dl[]={-1, 0, 1, 0};
    int dc[]={0, 1, 0, -1};

    struct poz{
        int lin, col;
    }C[n*m], v, p;
    int prim=1, ultim=1, k;

    C[ultim].lin=y; C[ultim].col=x;
    a[y][x]=ch;
    while (prim <= ultim)
          {
           p=C[prim++];
           for (k=0; k<4; k++)
               {
                v.lin=p.lin+dl[k];
                v.col=p.col+dc[k];
                if (a[v.lin][v.col] == 0)
                   {
                    a[v.lin][v.col]=ch;
                    C[++ultim]=v;
                   }
               }
          }

}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    if (left < 0 || top < 0 || right > m || bottom > n || left > right || top > bottom) return;
    this->Clear();
    this->DrawLine(left, top, left, bottom, '@');
    this->DrawLine(left, bottom, right, bottom, '@');
    this->DrawLine(right, bottom, right, top, '@');
    this->DrawLine(right, top, left, top, '@');
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    if (left < 0 || top < 0 || right > m || bottom > n || left > right || top > bottom) return;
    this->Clear();
    int i;
    for (i=left; i<=right; i++)
        DrawLine(i, top, i, bottom, ch);
}

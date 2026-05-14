#pragma once

// ≥нверс≥€ вс≥х елемент≥в
template <typename Container>
void inverse(Container& c)
{
    int n = c.Size();
    for (int i = 0; i < n / 2; i++)
    {
        auto tmp = c[i];
        c[i] = c[n - 1 - i];
        c[n - 1 - i] = tmp;
    }
}


// ≥нверс≥€ т≥льки елемент≥в, €к≥ задовольн€ють умов≥ pred
template <typename Container, typename Predicate>
void inverse_if(Container& c, Predicate pred)
{
    int left = 0;
    int right = c.Size() - 1;

    while (left < right)
    {
        while (left < right && !pred(c[left]))
            left++;

        while (left < right && !pred(c[right]))
            right--;

        if (left < right)
        {
            auto tmp = c[left];
            c[left] = c[right];
            c[right] = tmp;

            left++;
            right--;
        }
    }
}